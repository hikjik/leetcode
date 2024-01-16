import pandas as pd


def low_quality_problems(problems: pd.DataFrame) -> pd.DataFrame:
    return problems.query("2 * likes  < 3 * dislikes").sort_values("problem_id")[
        ["problem_id"]
    ]
