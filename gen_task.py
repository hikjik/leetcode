from argparse import ArgumentParser
from pathlib import Path
from typing import List

CMAKE_LISTS_FILE = 'CMakeLists.txt'
CMAKE_LISTS_FILE_CONTENT = """\
add_catch({task_name} test.cpp)
"""

SOLUTION_FILE = 'solution.hpp'
SOLUTION_FILE_CONTENT = """\
#pragma once

class Solution {
public:
};
"""

TEST_FILE = 'test.cpp'
TEST_FILE_CONTENT = """\
#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {}
"""


def update_cmake(new_task_name: str) -> None:
    words = new_task_name.lower().strip().split()
    new_task_name = '-'.join(words)

    lines: List[str] = []
    tasks: List[str] = [f"add_task({new_task_name})\n"]
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


def create_task_folder(new_task_name: str) -> None:
    words = new_task_name.lower().strip().split()

    task_path = Path("solutions") / Path('-'.join(words))
    task_path.mkdir()

    with open(task_path / SOLUTION_FILE, "w") as file:
        file.write(SOLUTION_FILE_CONTENT)

    with open(task_path / TEST_FILE, "w") as file:
        file.write(TEST_FILE_CONTENT)

    with open(task_path / CMAKE_LISTS_FILE, "w") as file:
        file.write(CMAKE_LISTS_FILE_CONTENT.format(task_name='_'.join(words)))


if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument('-t', '--task-name', type=str, required=True)
    args = parser.parse_args()

    create_task_folder(args.task_name)
    update_cmake(args.task_name)
