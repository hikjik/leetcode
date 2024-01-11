import pandas as pd


def page_recommendations(friendship: pd.DataFrame, likes: pd.DataFrame) -> pd.DataFrame:
    friends = pd.concat(
        [
            friendship.query("user1_id == 1").user2_id,
            friendship.query("user2_id == 1").user1_id,
        ]
    )
    already_liked = likes.query("user_id == 1").page_id
    return (
        likes.loc[
            ~likes.page_id.isin(already_liked) & likes.user_id.isin(friends),
            ["page_id"],
        ]
        .rename(columns={"page_id": "recommended_page"})
        .drop_duplicates()
    )
