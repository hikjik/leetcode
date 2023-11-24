import pandas as pd


def find_primary_department(employee: pd.DataFrame) -> pd.DataFrame:
    return employee[
        (employee.primary_flag == "Y")
        | ~employee.duplicated(subset="employee_id", keep=False)
    ][["employee_id", "department_id"]]
