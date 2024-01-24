import pandas as pd


def find_target_accounts(
    subscriptions: pd.DataFrame, streams: pd.DataFrame
) -> pd.DataFrame:
    stream_in_2021 = streams.query("stream_date.dt.year == 2021").account_id
    target_accounts_cnt = (
        subscriptions.query("start_date.dt.year <= 2021 and 2021 <= end_date.dt.year")
        .query("account_id not in @stream_in_2021")
        .account_id.nunique()
    )

    return pd.DataFrame({"accounts_count": [target_accounts_cnt]})
