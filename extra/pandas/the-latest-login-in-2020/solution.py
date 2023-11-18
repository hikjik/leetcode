import pandas as pd


def latest_login(logins: pd.DataFrame) -> pd.DataFrame:
    return (
        logins[logins.time_stamp.dt.year == 2020]
        .groupby("user_id")
        .agg(last_stamp=("time_stamp", "max"))
        .reset_index()
    )
