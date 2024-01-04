import colorsys
import json
import re
from glob import glob
from pathlib import Path
from typing import Any

from .meta import META_FILE
from .solution import SOLUTION_FILE

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

README_FILE = "README.md"
PROBLEM_LIST_FILE = "PROBLEM_LIST.md"

REGEX = r"""
//\s*Time:\s*(?P<time>O\(.*\))?.*
//\s*Space:\s*(?P<space>O\(.*\))?.*
(?://\s*Notes:\s*(?P<notes>.+)?)?
"""

PATTERN = re.compile(REGEX)


def get_cpp_problem(path: Path) -> dict[str, Any]:
    problem: dict[str, Any] = {}
    with open(path / META_FILE, "r") as file:
        problem.update(json.load(file))
    with open(path / SOLUTION_FILE, "r") as file:
        for it in re.finditer(PATTERN, file.read()):
            problem.update(it.groupdict())
            break
    slug = problem["slug"]
    problem["code"] = [f"[C++](./solutions/{slug}/{SOLUTION_FILE})"]
    return problem


def get_extra_problem(path: Path, ext: str) -> dict[str, Any]:
    problem: dict[str, Any] = {}
    with open(path / META_FILE, "r") as file:
        problem.update(json.load(file))
    slug = problem["slug"]
    if ext == "sql":
        problem["code"] = [f"[SQL](./extra/{ext}/{slug}/solution.sql)"]
    elif ext == "pandas":
        problem["code"] = [f"[PY](./extra/{ext}/{slug}/solution.py)"]
    elif ext == "bash":
        problem["code"] = [f"[SH](./extra/{ext}/{slug}/solution.sh)"]
    elif ext == "js":
        problem["code"] = [f"[JS](./extra/{ext}/{slug}/solution.js)"]
    return problem


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


def format_complexity(complexity: str) -> str:
    complexity = complexity.replace(" ", "&nbsp;")
    complexity = re.sub("\^\(([^()]*)\)", "<sup>\\1</sup>", complexity)
    complexity = re.sub("\^(.)", "<sup>\\1</sup>", complexity)
    return complexity


def update_readme_table() -> None:
    problems: dict[int, dict[str, Any]] = {}
    for path in sorted(glob("./solutions/*")):
        problem = get_cpp_problem(Path(path))
        problems[int(problem["id"])] = problem

    for ext in ["sql", "pandas", "bash", "js"]:
        for path in sorted(glob(f"./extra/{ext}/*")):
            problem = get_extra_problem(Path(path), ext)
            problem_id = int(problem["id"])
            if problem_id in problems:
                problems[problem_id]["code"].extend(problem["code"])
            else:
                problems[problem_id] = problem

    with open(README_FILE, mode="r") as file:
        lines = file.readlines()

    with open(README_FILE, mode="w") as readme_file, open(
        PROBLEM_LIST_FILE, mode="w"
    ) as list_file:
        for line in lines:
            readme_file.write(line)
            if line.startswith("<!-- accepted solution table -->"):
                break

        readme_file.write("\n")
        readme_file.write("|№|Title|Code|Difficulty|Time / Space|Tags|Notes|\n")
        readme_file.write("|-|-----|:--:|----------|:----------:|----|-----|\n")

        list_file.write("## Accepted solution\n")
        list_file.write("\n")
        list_file.write("|№|Title|Code|Difficulty|Time / Space|Tags|Notes|\n")
        list_file.write("|-|-----|:--:|----------|:----------:|----|-----|\n")

        tags_colors = get_colors(saturation=0.6, value=0.5)
        for i, (problem_id, problem) in enumerate(sorted(problems.items())):
            title = problem["title"]
            if problem.get("premium", False):
                title += " 🔒"
            slug = problem["slug"]
            url = f"https://leetcode.com/problems/{slug}/"
            difficulty = problem["difficulty"]
            difficulty_color = {
                "Easy": "darkgreen",
                "Medium": "darkorange",
                "Hard": "darkred",
            }[difficulty]
            difficulty_badge = badge(
                tag=difficulty,
                style="flat-square",
                color=difficulty_color,
            )
            tags = [
                badge(tag=tag, color=tags_colors[TAGS.index(tag)])
                for tag in problem["tags"]
            ]
            space = format_complexity(problem.get("space") or "")
            time = format_complexity(problem.get("time") or "")
            complexity = f"{time} / {space}" if time else ""
            notes = problem.get("notes") or ""
            code = ", ".join(problem["code"])
            if i < 1000:
                readme_file.write(
                    f"| {problem_id}. "
                    f"| [{title}]({url}) "
                    f"| {code} "
                    f"| {difficulty_badge} "
                    f"| {complexity}"
                    f"| {' '.join(tags)} "
                    f"| {notes} |\n"
                )
            list_file.write(
                f"| {problem_id}. "
                f"| [{title}]({url}) "
                f"| {code} "
                f"| {difficulty_badge} "
                f"| {complexity}"
                f"| {' '.join(tags)} "
                f"| {notes} |\n"
            )
