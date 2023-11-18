import pandas as pd


def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    return (
        employees.assign(total_time=employees.out_time - employees.in_time)
        .groupby(["emp_id", "event_day"])
        .total_time.sum()
        .reset_index()
        .rename(columns={"event_day": "day"})
    )
