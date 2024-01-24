import pandas as pd


def activity_participants(
    friends: pd.DataFrame, activities: pd.DataFrame
) -> pd.DataFrame:
    return (
        friends.groupby("activity")
        .id.count()
        .reset_index()
        .query("id != id.min() and id != id.max()")[["activity"]]
    )
