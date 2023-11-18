import pandas as pd


def count_followers(followers: pd.DataFrame) -> pd.DataFrame:
    return (
        followers.groupby("user_id")
        .follower_id.nunique()
        .reset_index(name="followers_count")
    )
