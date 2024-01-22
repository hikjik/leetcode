import pandas as pd


def reported_posts(actions: pd.DataFrame, removals: pd.DataFrame) -> pd.DataFrame:
    return (
        actions.merge(removals, on="post_id", how="left", suffixes=["_a, _r"])
        .query("action == 'report' and extra == 'spam'")
        .drop_duplicates(subset=["action_date", "post_id"])
        .groupby("action_date")
        .apply(lambda x: x.remove_date.count() * 100 / x.remove_date.agg("size"))
        .reset_index(name="average_daily_percent")
        .agg({"average_daily_percent": ["mean"]})
        .round(2)
    )
