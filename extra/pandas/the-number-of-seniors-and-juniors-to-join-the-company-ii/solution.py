import pandas as pd


def number_of_joiners(candidates: pd.DataFrame) -> pd.DataFrame:
    BUDGET = 70000

    hired_seniors = (
        candidates.query("experience == 'Senior'")
        .sort_values("salary")
        .query(f"salary.cumsum() < {BUDGET}")
    )
    hired_juniors = (
        candidates.query("experience == 'Junior'")
        .sort_values("salary")
        .query(f"salary.cumsum() < {BUDGET - hired_seniors.salary.sum()}")
    )
    return pd.concat([hired_seniors, hired_juniors])[["employee_id"]]
