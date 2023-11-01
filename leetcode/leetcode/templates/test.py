import json
import re
import subprocess
from pathlib import Path
from typing import Any

from .problem import DesignTestData, Problem, Struct, TestData, Variable

TEST_FILE = "test.cpp"
TEST_FILE_CONTENT_DEFAULT = """\
#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {{}}
"""
TEST_FILE_CONTENT = """\
#include <catch.hpp>

#include <solution.hpp>
{includes}\

TEST_CASE("Simple") {{
  struct TestCase {{
    {declaration_list};
  }};

  std::vector<TestCase> test_cases{{
      {initialization_list},
  }};

  for (const auto &[{identifier_list}] : test_cases) {{
    const {actual_type} actual = Solution::{call_expression};
    REQUIRE(expected == {actual});
  }}
}}
"""
DESIGN_TEST = """\
  {{
    {args_init}
    {constructor_init};

    {methods_calls};
  }}
"""
TEST_FILE_CONTENT_DESIGN = """\
#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {{
{tests}
}}
"""

TEST_DATA_MAPPINGS = {
    "[": "{",
    "]": "}",
    "null": "std::nullopt",
}


def get_test_data(content: str, test_examples: list[str]) -> list[TestData]:
    outputs = re.findall(
        r"Output:?[ \n]?(.*)\n",
        content,
    )

    if len(outputs) != len(test_examples):
        print("Not Equal", outputs, test_examples)

    test_data: list[TestData] = []
    for inputs, output in zip(test_examples, outputs):
        for old, new in TEST_DATA_MAPPINGS.items():
            inputs = inputs.replace(old, new)
            output = output.replace(old, new)
        test_data.append(
            TestData(
                inputs=inputs.split("\n"),
                output=output,
            )
        )
    return test_data


def get_design_test(
    methods: list[str], inputs_lists: list[list[str]], outputs: list[str]
) -> list[DesignTestData]:
    tests: list[DesignTestData] = []
    for method, inputs, output in zip(methods, inputs_lists, outputs):
        for old, new in TEST_DATA_MAPPINGS.items():
            inputs = [inp.replace(old, new) for inp in inputs]
            output = output.replace(old, new)
        tests.append(
            DesignTestData(
                method=method,
                inputs=inputs,
                output=output,
            )
        )
    return tests


def get_design_test_data(
    content: str, test_examples: list[str]
) -> list[list[DesignTestData]]:
    outputs_lists = re.findall(
        r"Output:?[ \n]?(.*)\n",
        content,
    )

    assert len(outputs_lists) == len(test_examples)

    def dumps_values(data: list[Any]) -> list[str]:
        return list(map(json.dumps, data))

    def load_list(data: str) -> list[str]:
        return dumps_values(json.loads(data))

    def load_lists(data: str) -> list[list[str]]:
        return [dumps_values(lst) for lst in json.loads(data)]

    test_data: list[list[DesignTestData]] = []
    for example, outputs_str in zip(test_examples, outputs_lists):
        methods_str, inputs_lists_str = example.split("\n")
        methods = json.loads(methods_str)
        outputs = load_list(outputs_str)
        inputs_lists = load_lists(inputs_lists_str)
        test_data.append(get_design_test(methods, inputs_lists, outputs))
    return test_data


def create_test_content(problem: Problem) -> str:
    assert 1 == len(problem.cls.methods)
    method = list(problem.cls.methods.values())[0]

    vars = method.args[:]
    vars.append(
        Variable(
            name="expected",
            type=method.return_type,
        )
    )
    struct = Struct(name="TestCase", vars=vars)

    includes = ""
    if "List" in [var.type for var in vars]:
        includes += "\n#include <list_node.h>\n"
    if "Tree" in [var.type for var in vars]:
        includes += "\n#include <tree_node.h>\n"

    actual_type = "auto"
    for type in ["List", "Tree"]:
        if type in method.return_type:
            actual_type = method.return_type
    actual = "actual"
    if method.return_type == "double":
        actual = f"Approx({actual})"

    test_data = get_test_data(problem.content, problem.test_examples)

    return TEST_FILE_CONTENT.format(
        includes=includes,
        declaration_list=struct.declaration_list(),
        initialization_list=struct.initialization_list(test_data),
        identifier_list=struct.identifier_list(),
        actual_type=actual_type,
        actual=actual,
        call_expression=method.call_expression(),
    )


def create_design_test_content(problem: Problem) -> str:
    tests: list[str] = []
    for test_data in get_design_test_data(
        problem.content,
        problem.test_examples,
    ):
        calls: list[str] = []
        for data in test_data[1:]:
            method = problem.cls.methods[data.method]

            call_expr = problem.cls.method_call(method.name, data.inputs)
            if data.output == "std::nullopt":
                calls.append(call_expr)
            else:
                if method.return_type == "double":
                    call_expr = f"Approx({call_expr})"
                if "vector" in method.return_type:
                    rt = method.return_type
                else:
                    rt = ""
                calls.append(f"REQUIRE({rt}{data.output} == {call_expr})")

        args_init = problem.cls.args_initialization(test_data[0].inputs)
        constructor_init = problem.cls.initialization()

        tests.append(
            DESIGN_TEST.format(
                args_init=args_init,
                constructor_init=constructor_init,
                methods_calls=";\n    ".join(calls),
            )
        )

    return TEST_FILE_CONTENT_DESIGN.format(tests="".join(tests))


def create_test_file(path: Path, problem: Problem) -> None:
    try:
        if problem.system_design:
            content = create_design_test_content(problem)
        else:
            content = create_test_content(problem)
    except Exception as e:
        print(e)
        content = TEST_FILE_CONTENT_DEFAULT

    with open(path / TEST_FILE, "w") as file:
        file.write(content)

    subprocess.run(["clang-format", "-i", path / TEST_FILE])
