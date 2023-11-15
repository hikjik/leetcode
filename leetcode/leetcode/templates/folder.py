from pathlib import Path

from .cmake import create_cmake_file, update_cmake
from .description import create_description_file
from .meta import create_meta_file
from .problem import Problem
from .solution import SOLUTION_FILE, create_solution_file
from .test import create_test_file


def create_problem_folder_cpp(problem: Problem) -> None:
    path = Path("solutions") / Path(problem.title_slug)

    if Path.exists(path):
        print(f"Already exists: {path / SOLUTION_FILE}")
        return

    path.mkdir()

    create_solution_file(path, problem)
    create_description_file(path, problem)
    create_test_file(path, problem)
    create_cmake_file(path, problem)
    create_meta_file(path, problem)
    update_cmake(problem.title_slug)

    print(f"Created file: {path / SOLUTION_FILE}")


def create_problem_folder_sql(problem: Problem) -> None:
    path = Path("extra") / "sql" / Path(problem.title_slug)
    if Path.exists(path):
        print(f"Already exists: {path / 'solution.sql'}")
        return

    path.mkdir()

    create_meta_file(path, problem)
    create_description_file(path, problem)
    with open(path / "solution.sql", "w") as file:
        file.write(problem.code_snippets["mysql"])


def create_problem_folder_pandas(problem: Problem) -> None:
    path = Path("extra") / "pandas" / Path(problem.title_slug)
    if Path.exists(path):
        print(f"Already exists: {path / 'solution.py'}")
        return

    path.mkdir()

    create_meta_file(path, problem)
    create_description_file(path, problem)
    with open(path / "solution.py", "w") as file:
        file.write(problem.code_snippets["pythondata"])


def create_problem_folder(problem: Problem, lang: str = "cpp") -> None:
    create = {
        "cpp": create_problem_folder_cpp,
        "sql": create_problem_folder_sql,
        "pandas": create_problem_folder_pandas,
    }[lang]
    create(problem)
