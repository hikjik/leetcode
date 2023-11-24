import pandas as pd


def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    return (
        employee.merge(
            employee,
            left_on="managerId",
            right_on="id",
            suffixes=["_emp", ""],
        )
        .groupby("id", as_index=False)
        .id_emp.count()
        .query("id_emp >= 5")[["name"]]
    )
