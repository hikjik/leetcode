import pandas as pd


def team_size(employee: pd.DataFrame) -> pd.DataFrame:
    return employee.assign(team_size=employee.groupby("team_id").transform("count"))[
        ["employee_id", "team_size"]
    ]
