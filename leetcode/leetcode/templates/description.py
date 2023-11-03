from pathlib import Path

from .problem import Problem

DESCRIPTION_FILE = "description.md"
DESCRIPTION_FILE_CONTENT = """\
# [{frontend_id}. {title}](https://leetcode.com/problems/{title_slug}/)

<p style="color:{color};">{difficulty}</p>

{content}
"""


def create_description_file(path: Path, problem: Problem) -> None:
    color = {
        "Easy": "green",
        "Medium": "orange",
        "Hard": "red",
    }.get(problem.difficulty)

    with open(path / DESCRIPTION_FILE, "w") as file:
        file.write(
            DESCRIPTION_FILE_CONTENT.format(
                frontend_id=problem.frontend_id,
                title=problem.title,
                title_slug=problem.title_slug,
                color=color,
                difficulty=problem.difficulty,
                content=problem.content,
            )
        )
