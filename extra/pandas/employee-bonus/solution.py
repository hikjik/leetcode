import pandas as pd


def employee_bonus(employee: pd.DataFrame, bonus: pd.DataFrame) -> pd.DataFrame:
    return employee.merge(bonus, how="left", on="empId").query(
        "bonus.isnull() or bonus < 1000"
    )[["name", "bonus"]]
