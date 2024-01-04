import json
from pathlib import Path

from .problem import Problem

META_FILE = "meta.json"


def create_meta_file(path: Path, problem: Problem) -> None:
    meta = {
        "id": f"{problem.frontend_id}",
        "title": problem.title,
        "url": f"https://leetcode.com/problems/{problem.title_slug}/",
        "slug": problem.title_slug,
        "difficulty": problem.difficulty,
        "premium": problem.premium,
        "tags": problem.tags,
    }
    with open(Path(path) / META_FILE, "w") as file:
        json.dump(meta, file, indent=4)
