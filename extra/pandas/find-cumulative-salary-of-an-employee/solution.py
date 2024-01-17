import pandas as pd


def cumulative_salary(employee: pd.DataFrame) -> pd.DataFrame:
    return (
        employee.assign(
            rank=employee.groupby("id").month.rank(ascending=False),
            month_as_day=pd.to_datetime(employee.month, format="%d"),
        )
        .query("rank != 1")
        .sort_values(by=["id", "month_as_day"])
        .groupby("id")
        .rolling("3D", on="month_as_day", min_periods=1)
        .salary.sum()
        .reset_index(name="Salary")
        .assign(month_as_day=lambda x: x.month_as_day.dt.day)
        .rename(columns={"month_as_day": "month"})
        .sort_values(by=["id", "month"], ascending=[True, False])
    )
