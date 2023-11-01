import re
import subprocess
from pathlib import Path

from .problem import Problem

SOLUTION_FILE = "solution.hpp"
SOLUTION_FILE_CONTENT = """\
#pragma once

{std_includes}
{utils_includes}

/*
  {id}. {title}
  https://leetcode.com/problems/{slug}/
  Difficulty: {difficulty}
  Tags: {tags}
  Time:
  Space:
*/

{snippet}
"""


def create_solution_file(path: Path, problem: Problem) -> None:
    code = problem.code_snippets["cpp"]

    if not problem.system_design:
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

    with open(path / SOLUTION_FILE, "w") as file:
        file.write(
            SOLUTION_FILE_CONTENT.format(
                snippet=code,
                std_includes=std_includes,
                utils_includes=utils_includes,
                id=problem.frontend_id,
                title=problem.title,
                slug=problem.title_slug,
                difficulty=problem.difficulty,
                tags=", ".join(problem.tags),
            )
        )

    subprocess.run(["clang-format", "-i", path / SOLUTION_FILE])
