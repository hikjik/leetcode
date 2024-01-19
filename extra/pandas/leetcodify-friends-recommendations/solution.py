import pandas as pd


def recommend_friends(listens: pd.DataFrame, friendship: pd.DataFrame) -> pd.DataFrame:
    return (
        listens.merge(listens, on=["day", "song_id"])
        .query("user_id_x != user_id_y")
        .groupby(["user_id_x", "user_id_y", "day"])
        .song_id.nunique()
        .reset_index()
        .query("song_id > 2")
        .drop_duplicates(subset=["user_id_x", "user_id_y"])
        .merge(
            pd.concat(
                [
                    friendship,
                    friendship.rename(
                        columns={"user2_id": "user1_id", "user1_id": "user2_id"}
                    ),
                ]
            ),
            left_on=["user_id_x", "user_id_y"],
            right_on=["user1_id", "user2_id"],
            how="left",
        )
        .query("user1_id.isnull()")
        .rename(columns={"user_id_x": "user_id", "user_id_y": "recommended_id"})[
            ["user_id", "recommended_id"]
        ]
    )
