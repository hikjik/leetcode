import colorsys
import json
import re
import subprocess
from argparse import ArgumentParser
from dataclasses import dataclass
from glob import glob
from pathlib import Path
from typing import Any

import requests

CMAKE_LISTS_FILE = "CMakeLists.txt"
CMAKE_LISTS_FILE_CONTENT = """\
add_catch(test_{task_name} test.cpp)
"""

SOLUTION_FILE = "solution.hpp"
SOLUTION_FILE_CONTENT = """\
#pragma once

{std_includes}
{utils_includes}
{snippet}
"""

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

DESCRIPTION_FILE = "description.md"
DESCRIPTION_FILE_CONTENT = """\
# [{frontend_id}. {title}](https://leetcode.com/problems/{title_slug}/)

<p style="color:{color};">{difficulty}</p>

{content}
"""

DIFFICULTY_COLOR_MAP = {
    "Easy": "green",
    "Medium": "orange",
    "Hard": "red",
}

LEETCODE_GRAPHQL_URL = "https://leetcode.com/graphql"

TAGS = [
    "Brainteaser",
    "Probability and Statistics",
    "Geometry",
    "Combinatorics",
    "Number Theory",
    "Game Theory",
    "Math",
    "Sliding Window",
    "Two Pointers",
    "Recursion",
    "Counting",
    "Enumeration",
    "Simulation",
    "Prefix Sum",
    "Divide and Conquer",
    "Rolling Hash",
    "Hash Function",
    "Interactive",
    "Monotonic Queue",
    "Monotonic Stack",
    "Data Stream",
    "Iterator",
    "Graph",
    "Breadth-First Search",
    "Depth-First Search",
    "Union Find",
    "Topological Sort",
    "Strongly Connected Component",
    "Biconnected Component",
    "Shortest Path",
    "Minimum Spanning Tree",
    "Eulerian Circuit",
    "Bit Manipulation",
    "Randomized",
    "Reservoir Sampling",
    "Rejection Sampling",
    "Database",
    "Concurrency",
    "Shell",
    "Line Sweep",
    "Merge Sort",
    "Quickselect",
    "Binary Search",
    "Counting Sort",
    "Radix Sort",
    "Bucket Sort",
    "Sorting",
    "Memoization",
    "Dynamic Programming",
    "Backtracking",
    "Greedy",
    "Bitmask",
    "Design",
    "Array",
    "Matrix",
    "Stack",
    "Queue",
    "Heap (Priority Queue)",
    "Linked List",
    "Doubly-Linked List",
    "Hash Table",
    "Tree",
    "Binary Tree",
    "Binary Search Tree",
    "Ordered Set",
    "Binary Indexed Tree",
    "Segment Tree",
    "String",
    "String Matching",
    "Trie",
    "Suffix Array",
]


def get_colors(
    n: int = len(TAGS),
    saturation: float = 1.0,
    value: float = 1.0,
):
    hsv_colors = [[x * 1.0 / n, saturation, value] for x in range(n)]
    hex_colors = []
    for hsv in hsv_colors:
        hsv = [int(x * 255) for x in colorsys.hsv_to_rgb(*hsv)]
        hex_colors.append(f"{hsv[0]:02x}{hsv[1]:02x}{hsv[2]:02x}")
    return hex_colors


def badge(
    tag: str,
    style: str = "flat-square",
    color: str = "blue",
) -> str:
    tag = tag.replace("-", " ")
    url = "https://img.shields.io/badge/"
    return f"<img src='{url}{tag}-{color}?style={style}'/>"


@dataclass
class TestData:
    inputs: list[str]
    output: str


@dataclass
class DesignTestData:
    method: str
    inputs: list[str]
    output: str


@dataclass
class Variable:
    name: str
    type: str

    def declaration(self) -> str:
        return f"{self.type} {self.name}"

    def initialization(self, value: str) -> str:
        return f"{self.declaration()}{self._fix(value)}"

    def designator(self, value: str) -> str:
        return f".{self.name}{self._fix(value)}"

    def _fix(self, value: str) -> str:
        s = "" if "vector" in self.type else "="
        if "char" in self.type:
            value = value.replace('"', "'")
        return f"{s}{value}"


@dataclass
class Struct:
    name: str
    vars: list[Variable]

    def declaration_list(self, sep: str = ";") -> str:
        return sep.join([var.declaration() for var in self.vars])

    def _init_list(self, values: list[str], sep: str = ",") -> str:
        assert len(self.vars) == len(values)

        init_list = []
        for var, value in zip(self.vars, values):
            init_list.append(var.designator(value))
        return sep.join(init_list) + ","

    def initialization_list(self, data: list[TestData], sep: str = ",") -> str:
        init_list = []
        for case in data:
            values = case.inputs + [case.output]
            init_list.append(f"{{{self._init_list(values)}}}")
        return sep.join(init_list)

    def identifier_list(self, sep: str = ",") -> str:
        return sep.join([v.name for v in self.vars])


@dataclass
class Function:
    name: str
    args: list[Variable]
    return_type: str

    def arguments_list(self, sep: str = ", ") -> str:
        return sep.join([arg.name for arg in self.args])

    def call_expression(self, values: list[str] | None = None) -> str:
        if values is None:
            return f"{self.name}({self.arguments_list()})"
        return f"{self.name}({', '.join(values)})"


@dataclass
class Class:
    constructor: Function
    methods: dict[str, Function]

    def _obj_name(self) -> str:
        return re.sub(r"(?<!^)(?=[A-Z])", "_", self.constructor.name).lower()

    def initialization(self) -> str:
        return f"auto {self._obj_name()}={self.constructor.call_expression()}"

    def args_initialization(self, values: list[str], sep=";") -> str:
        assert len(self.constructor.args) == len(values)
        if not values:
            return ""

        init_list = []
        for arg, value in zip(self.constructor.args, values):
            init_list.append(f"{arg.initialization(value)}")
        return sep.join(init_list) + ";"

    def method_call(self, name: str, values: list[str]) -> str:
        method = self.methods[name]
        return f"{self._obj_name()}.{method.call_expression(values)}"


@dataclass
class Task:
    id: str
    frontend_id: str
    title: str
    title_slug: str
    difficulty: str
    content: str
    code_snippets: dict[str, str]
    cls: Class
    test_examples: list[str]
    system_design: bool
    tags: list[str]


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


def transform_type(type: str) -> str:
    MAPPINGS = {
        "boolean": "bool",
        "character": "char",
        "double": "double",
        "integer": "int",
        "list": "std::vector",
        "ListNode": "List",
        "long": "long long",
        "string": "std::string",
        "TreeNode": "Tree",
    }
    for old, new in MAPPINGS.items():
        type = type.replace(old, new)
    for _ in range(3):
        type = re.sub(r"(.*)\[\]", r"std::vector<\1>", type)
    return type


def parse_function(meta: dict[str, Any]) -> Function:
    return Function(
        name=meta["name"],
        args=[
            Variable(
                name=parameter["name"],
                type=transform_type(parameter["type"]),
            )
            for parameter in meta["params"]
        ],
        return_type=transform_type(meta["return"]["type"]),
    )


def parse_cls(meta: dict[str, Any]) -> Class:
    if "classname" in meta:
        return Class(
            constructor=Function(
                name=meta["classname"],
                args=[
                    Variable(
                        name=parameter["name"],
                        type=transform_type(parameter["type"]),
                    )
                    for parameter in meta["constructor"]["params"]
                    if parameter.get("lang", None) != "c"
                ],
                return_type="void",
            ),
            methods={m["name"]: parse_function(m) for m in meta["methods"]},
        )
    return Class(
        constructor=Function(
            name="Solution",
            args=[],
            return_type="void",
        ),
        methods={meta["name"]: parse_function(meta)},
    )


def get_task_info(task_slug: str) -> Task:
    query = """
    query questionData($titleSlug: String!) {
        question(titleSlug: $titleSlug) {
            questionId
            questionFrontendId
            title
            titleSlug
            difficulty
            content
            codeSnippets {
                langSlug
                code
            }
            topicTags {
                name
            }
            metaData
            exampleTestcaseList
        }
    }
    """

    data = {
        "operationName": "questionData",
        "variables": {"titleSlug": task_slug},
        "query": query,
    }

    response = requests.post(LEETCODE_GRAPHQL_URL, json=data)
    question = response.json()["data"]["question"]

    content = re.sub(re.compile("<.*?>"), "", question["content"])
    content = content.replace("&quot;", '"')

    snippets = {s["langSlug"]: s["code"] for s in question["codeSnippets"]}

    return Task(
        id=question["questionId"],
        frontend_id=question["questionFrontendId"],
        title=question["title"],
        title_slug=question["titleSlug"],
        difficulty=question["difficulty"],
        content=content,
        code_snippets=snippets,
        cls=parse_cls(json.loads(question["metaData"])),
        test_examples=question["exampleTestcaseList"],
        system_design="systemdesign" in question["metaData"],
        tags=[tag["name"] for tag in question["topicTags"]],
    )


def get_daily_question_slug() -> str:
    query = """
    query questionOfToday {
        activeDailyCodingChallengeQuestion {
            question {
                titleSlug
            }
        }
    }
    """

    response = requests.post(
        LEETCODE_GRAPHQL_URL,
        json={
            "query": query,
        },
    )
    data = response.json()["data"]
    question = data["activeDailyCodingChallengeQuestion"]["question"]
    return question["titleSlug"]


def update_cmake(task_slug: str) -> None:
    lines: list[str] = []
    tasks: list[str] = [f"add_task({task_slug})\n"]

    with open(CMAKE_LISTS_FILE, "r+") as file:
        for line in file:
            if line.startswith("add_task"):
                tasks.append(line)
            else:
                lines.append(line)

        file.seek(0)

        for line in lines:
            file.write(line)
        for task in sorted(tasks):
            file.write(task)


def create_description_file(task_path: Path, task: Task) -> None:
    with open(task_path / DESCRIPTION_FILE, "w") as file:
        file.write(
            DESCRIPTION_FILE_CONTENT.format(
                frontend_id=task.frontend_id,
                title=task.title,
                title_slug=task.title_slug,
                color=DIFFICULTY_COLOR_MAP[task.difficulty],
                difficulty=task.difficulty,
                content=task.content,
            )
        )


def create_solution_file(task_path: Path, task: Task) -> None:
    code = task.code_snippets["cpp"]

    if not task.system_design:
        code = re.sub(r"\n\s*(.*\(.*\)\s*\{\s*)", r"\n  static \1", code)

    std_includes = ""
    for p in ["vector", "string"]:
        code, n = re.subn(rf"([ (<])({p})", r"\1std::\2", code)
        if n:
            std_includes += f"#include <{p}>\n"

    utils_includes = ""
    if "ListNode" in code:
        utils_includes += "\n#include <list_node.h>\n"
    if "TreeNode" in code:
        utils_includes += "\n#include <tree_node.h>\n"

    with open(task_path / SOLUTION_FILE, "w") as file:
        file.write(
            SOLUTION_FILE_CONTENT.format(
                snippet=code,
                std_includes=std_includes,
                utils_includes=utils_includes,
            )
        )

    subprocess.run(["clang-format", "-i", task_path / SOLUTION_FILE])


def create_test_content(task: Task) -> str:
    assert 1 == len(task.cls.methods)
    method = list(task.cls.methods.values())[0]

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

    test_data = get_test_data(task.content, task.test_examples)

    return TEST_FILE_CONTENT.format(
        includes=includes,
        declaration_list=struct.declaration_list(),
        initialization_list=struct.initialization_list(test_data),
        identifier_list=struct.identifier_list(),
        actual_type=actual_type,
        actual=actual,
        call_expression=method.call_expression(),
    )


def create_design_test_content(task: Task) -> str:
    tests: list[str] = []
    for test_data in get_design_test_data(task.content, task.test_examples):
        calls: list[str] = []
        for data in test_data[1:]:
            method = task.cls.methods[data.method]

            call_expr = task.cls.method_call(method.name, data.inputs)
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

        args_init = task.cls.args_initialization(test_data[0].inputs)
        constructor_init = task.cls.initialization()

        tests.append(
            DESIGN_TEST.format(
                args_init=args_init,
                constructor_init=constructor_init,
                methods_calls=";\n    ".join(calls),
            )
        )

    return TEST_FILE_CONTENT_DESIGN.format(tests="".join(tests))


def create_test_file(task_path: Path, task: Task) -> None:
    try:
        if task.system_design:
            content = create_design_test_content(task)
        else:
            content = create_test_content(task)
    except Exception as e:
        print(e)
        content = TEST_FILE_CONTENT_DEFAULT

    with open(task_path / TEST_FILE, "w") as file:
        file.write(content)

    subprocess.run(["clang-format", "-i", task_path / TEST_FILE])


def create_cmake_file(task_path: Path, task: Task) -> None:
    with open(task_path / CMAKE_LISTS_FILE, "w") as file:
        file.write(
            CMAKE_LISTS_FILE_CONTENT.format(
                task_name=task.title_slug.replace("-", "_"),
            )
        )


def create_task_folder(task_slug: str) -> None:
    task = get_task_info(task_slug)
    task_path = Path("solutions") / Path(task_slug)

    if Path.exists(task_path):
        print(f"Already exists: {task_path}")
        return

    task_path.mkdir()

    create_solution_file(task_path, task)
    create_description_file(task_path, task)
    create_test_file(task_path, task)
    create_cmake_file(task_path, task)
    update_cmake(task_slug)

    print(f"Created file: {task_path / SOLUTION_FILE}")


def update_readme_table() -> None:
    slugs: set[int] = set()
    problems: list[dict[str, Any]] = []

    try:
        with open("res/problems.json", mode="r") as file:
            for row in json.load(file):
                slugs.add(row["Slug"])
                problems.append(row)
    except FileNotFoundError:
        pass

    for path in sorted(glob("./solutions/*")):
        task_path = Path(path)
        if task_path.name in slugs:
            continue

        try:
            task = get_task_info(task_path.name)
        except Exception as e:
            print(e)
            continue

        problems.append(
            {
                "ID": task.frontend_id,
                "Title": task.title,
                "Slug": task.title_slug,
                "Difficulty": task.difficulty,
                "Tags": task.tags,
                "Space": "",
                "Time": "",
                "Notes": "",
            }
        )

    problems.sort(key=lambda x: int(x["ID"]))

    with open("res/problems.json", mode="w") as file:
        json.dump(problems, file, indent=4)

    with open("README.md", mode="r") as file:
        lines = file.readlines()

    with open("README.md", mode="w") as file:
        for line in lines:
            file.write(line)
            if line.startswith("## Accepted solution"):
                break

        file.write("\n")
        file.write("|№|Title|Code|Difficulty|Time|Space|Tags|Notes|\n")
        file.write("|-|-----|:--:|----------|:--:|:---:|----|-----|\n")

        colors = get_colors(saturation=0.6, value=0.5)
        for problem in problems:
            task_id = problem["ID"]
            title = problem["Title"]
            slug = problem["Slug"]
            url = f"https://leetcode.com/problems/{slug}/"
            difficulty_badge = badge(
                tag=problem["Difficulty"],
                style="flat-square",
                color="dark" + DIFFICULTY_COLOR_MAP[problem["Difficulty"]],
            )
            tags = [
                badge(tag=tag, color=colors[TAGS.index(tag)]) for tag in problem["Tags"]
            ]
            space = problem["Space"]
            time = problem["Time"]
            notes = problem["Notes"]
            file.write(
                f"| {task_id}. "
                f"| [{title}]({url}) "
                f"| [C++](./solutions/{slug}/solution.hpp) "
                f"| {difficulty_badge} "
                f"| {time} "
                f"| {space} "
                f"| {' '.join(tags)} "
                f"| {notes} |\n"
            )


if __name__ == "__main__":
    parser = ArgumentParser()
    subparsers = parser.add_subparsers(title="Commands", dest="cmd")

    get_task = subparsers.add_parser(
        "get",
        help="Get LeetCode Problem",
    )
    get_task.add_argument(
        "slug",
        type=str,
        help="LeetCode Problem Slug",
    )
    get_task.add_argument(
        "--lang",
        type=str,
        choices=["cpp"],
        default="cpp",
        required=False,
    )

    get_daily = subparsers.add_parser(
        "get-daily",
        help="Get Daily LeetCode Problem",
    )

    get_descriptions = subparsers.add_parser(
        "get-descriptions",
        help="Update LeetCode Problems Description",
    )

    update_readme = subparsers.add_parser(
        "update-readme",
        help="Update README.md",
    )

    args = parser.parse_args()

    if args.cmd is None:
        parser.print_help()
    elif args.cmd == "get":
        create_task_folder(args.slug)
    elif args.cmd == "get-daily":
        create_task_folder(get_daily_question_slug())
    elif args.cmd == "get-descriptions":
        for path in glob("./solutions/*", recursive=False):
            task_path = Path(path)
            task = get_task_info(task_path.name)
            create_description_file(task_path, task)
    elif args.cmd == "update-readme":
        update_readme_table()
    else:
        print(f"Unknown command {args.cmd}")
        parser.print_help()
