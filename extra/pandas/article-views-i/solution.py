import pandas as pd


def article_views(views: pd.DataFrame) -> pd.DataFrame:
    return (
        views[views.author_id == views.viewer_id]
        .drop_duplicates(subset="author_id")
        .rename(columns={"author_id": "id"})
        .sort_values(by="id")[["id"]]
    )
