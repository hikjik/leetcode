import pandas as pd


def department_highest_salary(
    employee: pd.DataFrame, department: pd.DataFrame
) -> pd.DataFrame:
    return (
        employee.groupby("departmentId")
        .apply(lambda x: x[x.salary == x.salary.max()])
        .droplevel(level=0)
        .merge(department, left_on="departmentId", right_on="id")
        .rename(
            columns={"name_y": "Department", "name_x": "Employee", "salary": "Salary"}
        )[["Department", "Employee", "Salary"]]
    )
