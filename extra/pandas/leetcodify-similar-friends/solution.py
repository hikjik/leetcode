import pandas as pd


def leetcodify_similar_friends(
    listens: pd.DataFrame, friendship: pd.DataFrame
) -> pd.DataFrame:
    return (
        listens.merge(listens, on=["day", "song_id"])
        .query("user_id_x < user_id_y")
        .groupby(["user_id_x", "user_id_y", "day"])
        .song_id.nunique()
        .reset_index()
        .query("song_id > 2")
        .merge(
            friendship,
            left_on=["user_id_x", "user_id_y"],
            right_on=["user1_id", "user2_id"],
        )[["user1_id", "user2_id"]]
        .drop_duplicates()
    )
