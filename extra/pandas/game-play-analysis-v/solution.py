import pandas as pd


def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    def custom_round(x, decimals=2):
        offset = 10**decimals
        return int(x * offset + 0.5) / offset

    return (
        activity.assign(
            install_dt=lambda x: x.groupby("player_id").event_date.transform("min"),
            is_retained=lambda x: x.event_date == x.install_dt + pd.DateOffset(days=1),
        )
        .groupby("install_dt")
        .agg(
            installs=("player_id", "nunique"),
            Day1_retention=("is_retained", "sum"),
        )
        .reset_index()
        .assign(
            Day1_retention=lambda x: (x.Day1_retention / x.installs).apply(custom_round)
        )
    )
