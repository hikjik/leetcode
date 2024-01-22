import pandas as pd


def article_views(views: pd.DataFrame) -> pd.DataFrame:
    return (
        views.groupby(["viewer_id", "view_date"])
        .article_id.nunique()
        .reset_index(name="article_count")
        .query("article_count > 1")[["viewer_id"]]
        .drop_duplicates()
        .rename(columns={"viewer_id": "id"})
        .sort_values("id")
    )
