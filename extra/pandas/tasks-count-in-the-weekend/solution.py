import pandas as pd


def count_tasks(tasks: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame(
        {
            "weekend_cnt": [(tasks.submit_date.dt.weekday > 4).sum()],
            "working_cnt": [(tasks.submit_date.dt.weekday < 5).sum()],
        }
    )
