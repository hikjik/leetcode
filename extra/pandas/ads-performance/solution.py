import pandas as pd


def ads_performance(ads: pd.DataFrame) -> pd.DataFrame:
    return (
        ads.groupby(by="ad_id")
        .action.apply(lambda x: (x == "Clicked").sum() * 100 / (x != "Ignored").sum())
        .fillna(0)
        .round(2)
        .reset_index(name="ctr")
        .sort_values(by=["ctr", "ad_id"], ascending=[False, True])
    )
