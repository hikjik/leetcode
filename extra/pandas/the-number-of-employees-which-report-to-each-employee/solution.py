import pandas as pd


def count_employees(employees: pd.DataFrame) -> pd.DataFrame:
    return (
        employees.merge(
            employees,
            left_on="reports_to",
            right_on="employee_id",
            suffixes=["_emp", ""],
        )
        .groupby(by=["employee_id", "name"])
        .agg(
            reports_count=("employee_id_emp", "size"),
            average_age=("age_emp", "mean"),
        )
        .apply(lambda x: round(x + 1e-9))
    ).reset_index()
