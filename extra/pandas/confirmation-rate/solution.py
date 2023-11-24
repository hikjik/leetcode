import pandas as pd


def confirmation_rate(
    signups: pd.DataFrame, confirmations: pd.DataFrame
) -> pd.DataFrame:
    return (
        signups.merge(confirmations, on="user_id")
        .groupby("user_id")
        .action.apply(lambda x: (x == "confirmed").mean().round(2))
        .reset_index(name="rate")
    )
