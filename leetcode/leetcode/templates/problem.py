import json
import re
from dataclasses import dataclass
from typing import Any


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
class Problem:
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


def parse_problem(data: dict[str, Any]) -> Problem:
    question = data["data"]["question"]

    content = re.sub(re.compile("<.*?>"), "", question["content"])
    content = content.replace("&quot;", '"')

    snippets = {s["langSlug"]: s["code"] for s in question["codeSnippets"]}

    return Problem(
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
