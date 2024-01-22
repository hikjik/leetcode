import pandas as pd


def new_users_daily_count(traffic: pd.DataFrame) -> pd.DataFrame:
    return (
        traffic.query("activity == 'login'")
        .groupby("user_id")
        .activity_date.min()
        .reset_index(name="login_date")
        .query("login_date.between('2019-04-01', '2019-06-30')")
        .groupby("login_date")
        .user_id.nunique()
        .reset_index(name="user_count")
    )
