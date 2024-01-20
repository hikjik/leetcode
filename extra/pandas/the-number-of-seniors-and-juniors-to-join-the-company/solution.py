import pandas as pd


def count_seniors_and_juniors(candidates: pd.DataFrame) -> pd.DataFrame:
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
    return pd.DataFrame(
        {
            "experience": ["Senior", "Junior"],
            "accepted_candidates": [len(hired_seniors), len(hired_juniors)],
        }
    )
