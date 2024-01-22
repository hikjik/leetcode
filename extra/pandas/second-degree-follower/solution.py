import pandas as pd


def second_degree_follower(follow: pd.DataFrame) -> pd.DataFrame:
    return (
        follow.query("followee in follower")
        .groupby("followee")
        .follower.nunique()
        .reset_index(name="num")
        .rename(columns={"followee": "follower"})
    )
