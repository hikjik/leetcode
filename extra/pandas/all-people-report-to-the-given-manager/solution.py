import pandas as pd


def find_reporting_people(employees: pd.DataFrame) -> pd.DataFrame:
    return (
        employees.merge(
            employees,
            left_on="manager_id",
            right_on="employee_id",
            suffixes=["", "_2"],
        )
        .merge(
            employees,
            left_on="manager_id_2",
            right_on="employee_id",
            suffixes=["", "_3"],
        )
        .query("employee_id != manager_id and manager_id_3 == 1")[["employee_id"]]
    )
