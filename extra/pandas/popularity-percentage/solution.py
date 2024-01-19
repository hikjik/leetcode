import pandas as pd


def popularity_percentage(friends: pd.DataFrame) -> pd.DataFrame:
    friends = pd.concat(
        [friends, friends.rename(columns={"user1": "user2", "user2": "user1"})]
    )
    total_users = friends.user1.nunique()
    return (
        friends.groupby("user1")
        .user2.apply(lambda x: x.nunique() * 100 / total_users)
        .round(2)
        .reset_index(name="percentage_popularity")
    )
