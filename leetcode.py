from argparse import ArgumentParser
from dataclasses import dataclass
from glob import glob
from pathlib import Path
import re

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
TEST_FILE_CONTENT = """\
#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {}
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


@dataclass
class Task:
    id: str
    frontend_id: str
    title: str
    title_slug: str
    difficulty: str
    content: str
    code_snippets: dict[str, str]
    meta_data: str
    test_cases: list[str]


def get_daily_question_slug() -> Task:
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

    snippets = {s["langSlug"]: s["code"] for s in question["codeSnippets"]}

    return Task(
        id=question["questionId"],
        frontend_id=question["questionFrontendId"],
        title=question["title"],
        title_slug=question["titleSlug"],
        difficulty=question["difficulty"],
        content=question["content"],
        code_snippets=snippets,
        meta_data=question["metaData"],
        test_cases=question["exampleTestcaseList"],
    )


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
    code = re.sub(r"\n\s*(.*\(.*\) \{\n)", r"\n    static \1", code)

    std_includes = ""
    for p in ["vector", "string"]:
        if p in code:
            code = code.replace(p, "std::" + p)
            std_includes += f"#include <{p}>\n"

    utils_includes = ""
    if "ListNode" in code:
        utils_includes += f"\n#include <list_node>\n"
    if "TreeNode" in code:
        utils_includes += f"\n#include <tree_node>\n"

    with open(task_path / SOLUTION_FILE, "w") as file:
        file.write(
            SOLUTION_FILE_CONTENT.format(
                snippet=code,
                std_includes=std_includes,
                utils_includes=utils_includes,
            )
        )


def create_test_file(task_path: Path, task: Task) -> None:
    with open(task_path / TEST_FILE, "w") as file:
        file.write(TEST_FILE_CONTENT)


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
    else:
        print(f"Unknown command {args.cmd}")
        parser.print_help()
