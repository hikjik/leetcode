import pandas as pd


def median_employee_salary(employee: pd.DataFrame) -> pd.DataFrame:
    return (
        employee.sort_values(by=["salary", "id"])
        .groupby("company")
        .apply(lambda x: x.iloc[(len(x) - 1) // 2 : len(x) // 2 + 1])
    )
