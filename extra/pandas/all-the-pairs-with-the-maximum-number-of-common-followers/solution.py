import pandas as pd


def find_pairs(relations: pd.DataFrame) -> pd.DataFrame:
    return (
        relations.merge(relations, on="follower_id")
        .query("user_id_x < user_id_y")
        .groupby(["user_id_x", "user_id_y"])
        .follower_id.count()
        .reset_index(name="cnt")
        .query("cnt == cnt.max()")
        .drop(columns="cnt")
        .rename(columns={"user_id_x": "user1_id", "user_id_y": "user2_id"})
    )
