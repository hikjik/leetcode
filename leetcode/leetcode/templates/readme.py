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

REGEX = r"""
//\s*Time:\s*(?P<time>O\(.*\))?.*
//\s*Space:\s*(?P<space>O\(.*\))?.*
(?://\s*Notes:\s*(?P<notes>.+)?)?
"""

PATTERN = re.compile(REGEX)


def get_problem(path: Path) -> dict[str, Any]:
    problem: dict[str, Any] = {}
    with open(path / META_FILE, "r") as file:
        problem.update(json.load(file))
    with open(path / SOLUTION_FILE, "r") as file:
        for it in re.finditer(PATTERN, file.read()):
            problem.update(it.groupdict())
            break
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
    complexity = re.sub("\^(.)", "<sup>\\1</sup>", complexity)
    return complexity


def update_readme_table() -> None:
    problems: list[dict[str, Any]] = []
    for path in sorted(glob("./solutions/*")):
        problem = get_problem(Path(path))
        problems.append(problem)

    problems.sort(key=lambda x: int(x["id"]))

    with open(README_FILE, mode="r") as file:
        lines = file.readlines()

    with open(README_FILE, mode="w") as file:
        for line in lines:
            file.write(line)
            if line.startswith("## Accepted solution"):
                break

        file.write("\n")
        file.write("|№|Title|Code|Difficulty|Time|Space|Tags|Notes|\n")
        file.write("|-|-----|:--:|----------|:--:|:---:|----|-----|\n")

        tags_colors = get_colors(saturation=0.6, value=0.5)
        for problem in problems:
            problem_id = problem["id"]
            title = problem["title"]
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
            space = format_complexity(problem["space"] or "")
            time = format_complexity(problem["time"] or "")
            notes = problem["notes"] or ""
            file.write(
                f"| {problem_id}. "
                f"| [{title}]({url}) "
                f"| [C++](./solutions/{slug}/solution.hpp) "
                f"| {difficulty_badge} "
                f"| {time} "
                f"| {space} "
                f"| {' '.join(tags)} "
                f"| {notes} |\n"
            )
