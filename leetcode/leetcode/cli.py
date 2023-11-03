import typing as tp

import click

from .client import Client
from .templates import create_problem_folder, parse_problem, update_readme_table


def get_problem_slug_from_list(json: dict[str, tp.Any], id: int) -> str:
    data = json["data"]
    questions = data["problemsetQuestionList"]["questions"]
    for question in questions:
        if int(question["frontendQuestionId"]) == id:
            return question["titleSlug"]
    raise


def get_daily_problem_slug(json: dict[str, tp.Any]) -> str:
    data = json["data"]
    question = data["activeDailyCodingChallengeQuestion"]["question"]
    return question["titleSlug"]


@click.group()
def cli() -> None:
    """LeetCode tool base command"""
    pass


@cli.command()
@click.argument(
    "problem_id",
    type=int,
    required=False,
)
@click.option(
    "-s",
    "--slug",
    type=str,
    help="LeetCode Problem Slug",
)
@click.option(
    "-d",
    "--daily",
    is_flag=True,
    default=False,
    help="Get Problem of day",
)
def pull(problem_id: int, slug: str, daily: bool) -> None:
    client = Client()
    if problem_id is not None:
        data = client.question_list(limit=1, skip=problem_id - 1)
        slug = get_problem_slug_from_list(data, problem_id)
    elif daily:
        slug = get_daily_problem_slug(client.question_of_today())

    if slug is None:
        ctx = click.get_current_context()
        ctx.fail(ctx.get_help())

    data = client.question_data(slug)
    problem = parse_problem(data)
    create_problem_folder(problem)


@cli.command()
def update_readme() -> None:
    update_readme_table()
