from pathlib import Path

from .cmake import create_cmake_file, update_cmake
from .description import create_description_file
from .problem import Problem
from .solution import SOLUTION_FILE, create_solution_file
from .test import create_test_file


def create_problem_folder(problem: Problem) -> None:
    path = Path("solutions") / Path(problem.title_slug)

    if Path.exists(path):
        print(f"Already exists: {path}")
        return

    path.mkdir()

    create_solution_file(path, problem)
    create_description_file(path, problem)
    create_test_file(path, problem)
    create_cmake_file(path, problem)
    update_cmake(problem.title_slug)

    print(f"Created file: {path / SOLUTION_FILE}")
