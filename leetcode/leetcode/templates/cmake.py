from pathlib import Path

from .problem import Problem

CMAKE_LISTS_FILE = "CMakeLists.txt"
CMAKE_LISTS_FILE_CONTENT = """\
add_catch(test_{problem_name} test.cpp)
"""


def update_cmake(slug: str) -> None:
    lines: list[str] = []
    problems: list[str] = [f"add_task({slug})\n"]

    with open(CMAKE_LISTS_FILE, "r+") as file:
        for line in file:
            if line.startswith("add_task"):
                problems.append(line)
            else:
                lines.append(line)

        file.seek(0)

        for line in lines:
            file.write(line)
        for problem in sorted(problems):
            file.write(problem)


def create_cmake_file(path: Path, problem: Problem) -> None:
    with open(path / CMAKE_LISTS_FILE, "w") as file:
        file.write(
            CMAKE_LISTS_FILE_CONTENT.format(
                problem_name=problem.title_slug.replace("-", "_"),
            )
        )
