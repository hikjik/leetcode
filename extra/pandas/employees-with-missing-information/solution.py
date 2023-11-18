import pandas as pd


def find_employees(employees: pd.DataFrame, salaries: pd.DataFrame) -> pd.DataFrame:
    return (
        employees.merge(salaries, on="employee_id", how="outer")
        .query("name.isna() or salary.isna()")[["employee_id"]]
        .sort_values(by="employee_id", ascending=True)
    )
