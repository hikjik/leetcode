import pandas as pd


def find_latest_salaries(salary: pd.DataFrame) -> pd.DataFrame:
    return (
        salary.sort_values(by="salary", ascending=False)
        .drop_duplicates(subset="emp_id")
        .sort_values(by="emp_id")
    )
