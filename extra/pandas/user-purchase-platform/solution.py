import pandas as pd


def user_purchase(spending: pd.DataFrame) -> pd.DataFrame:
    date_with_platforms = pd.merge(
        pd.DataFrame({"spend_date": spending.spend_date.unique()}),
        pd.DataFrame({"platform": ["mobile", "desktop", "both"]}),
        how="cross",
    )

    return (
        spending.groupby(by=["spend_date", "user_id"])
        .agg(
            amount=("amount", "sum"),
            platform=("platform", lambda x: "both" if len(x.unique()) == 2 else x),
        )
        .reset_index()
        .merge(date_with_platforms, on=["spend_date", "platform"], how="right")
        .groupby(by=["spend_date", "platform"])
        .agg(total_amount=("amount", "sum"), total_users=("user_id", "count"))
        .reset_index()
    )
