import pandas as pd


def report_contiguous_dates(
    failed: pd.DataFrame, succeeded: pd.DataFrame
) -> pd.DataFrame:
    return (
        pd.concat(
            [
                failed.assign(task_state="failed").rename(
                    columns={"fail_date": "task_date"}
                ),
                succeeded.assign(task_state="succeeded").rename(
                    columns={"success_date": "task_date"}
                ),
            ]
        )
        .query("task_date.between('2019-01-01', '2019-12-31')")
        .sort_values(by="task_date")
        .assign(num=lambda x: x.task_date.rank() - x.index)
        .groupby(by=["num", "task_state"])
        .agg(
            start_date=("task_date", "min"),
            end_date=("task_date", "max"),
        )
        .reset_index(names=["num", "period_state"])
        .drop(columns="num")
        .sort_values(by="start_date")
    )
