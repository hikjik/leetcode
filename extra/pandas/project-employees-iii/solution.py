import pandas as pd


def project_employees(project: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:
    return project.assign(
        rank=project.merge(employee, on="employee_id", how="left")
        .groupby("project_id")
        .experience_years.rank(ascending=False, method="dense")
    ).query("rank == 1")[["project_id", "employee_id"]]
