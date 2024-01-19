import pandas as pd


def recommend_page(friendship: pd.DataFrame, likes: pd.DataFrame) -> pd.DataFrame:
    return (
        pd.concat(
            [
                friendship.rename(
                    columns={"user1_id": "user_id", "user2_id": "friend_id"}
                ),
                friendship.rename(
                    columns={"user2_id": "user_id", "user1_id": "friend_id"}
                ),
            ]
        )
        .merge(
            likes,
            left_on="friend_id",
            right_on="user_id",
            how="inner",
            suffixes=["", "_y"],
        )
        .groupby(["user_id", "page_id"])
        .friend_id.count()
        .reset_index(name="friends_likes")
        .merge(
            likes,
            on=["user_id", "page_id"],
            how="left",
            indicator=True,
        )
        .query("_merge == 'left_only'")
        .drop(columns="_merge")
    )
