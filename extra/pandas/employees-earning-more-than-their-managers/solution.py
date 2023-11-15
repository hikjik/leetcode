import pandas as pd


def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    return (
        employee.merge(
            employee,
            how="inner",
            left_on="managerId",
            right_on="id",
            suffixes=["_emp", "_mgr"],
        )
        .query("salary_emp > salary_mgr")[["name_emp"]]
        .rename(columns={"name_emp": "Employee"})
    )
