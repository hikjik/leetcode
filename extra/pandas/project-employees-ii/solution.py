import pandas as pd


def project_employees_ii(project: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:
    return (
        project.groupby("project_id")
        .employee_id.count()
        .rank(ascending=False)
        .reset_index(name="project_rank")
        .query("project_rank == 1")[["project_id"]]
    )
