import pandas as pd


def find_students(departments: pd.DataFrame, students: pd.DataFrame) -> pd.DataFrame:
    return students.merge(
        departments,
        left_on="department_id",
        right_on="id",
        how="left",
        suffixes=["", "_dep"],
    ).query("id_dep.isnull()")[["id", "name"]]
