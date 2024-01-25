import pandas as pd


def employees_of_same_salary(employees: pd.DataFrame) -> pd.DataFrame:
    return (
        employees.groupby("salary")
        .filter(lambda x: len(x) > 1)
        .assign(team_id=lambda x: x.salary.rank(method="dense"))
        .sort_values(["team_id", "employee_id"])
    )
