import pandas as pd


def top_travellers(users: pd.DataFrame, rides: pd.DataFrame) -> pd.DataFrame:
    return (
        users.merge(
            right=(
                rides.groupby("user_id")
                .distance.sum()
                .reset_index(name="travelled_distance")
            ),
            left_on="id",
            right_on="user_id",
            how="left",
        )
        .fillna(0)
        .sort_values(
            by=["travelled_distance", "name"],
            ascending=[False, True],
        )[["name", "travelled_distance"]]
    )
