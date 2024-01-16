import pandas as pd


def get_total_distance(users: pd.DataFrame, rides: pd.DataFrame) -> pd.DataFrame:
    return (
        users.merge(rides, on="user_id", how="left")
        .groupby(["user_id", "name"])
        .distance.sum()
        .reset_index(name="traveled distance")
    )
