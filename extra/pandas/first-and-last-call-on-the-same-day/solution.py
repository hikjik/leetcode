import pandas as pd


def same_day_calls(calls: pd.DataFrame) -> pd.DataFrame:
    return (
        pd.concat(
            [
                calls.rename(columns={"caller_id": "user1", "recipient_id": "user2"}),
                calls.rename(columns={"recipient_id": "user1", "caller_id": "user2"}),
            ]
        )
        .sort_values("call_time")
        .assign(
            date=lambda x: x.call_time.dt.date,
            rank_earliest_calls=lambda x: x.groupby(["user1", "date"]).call_time.rank(
                method="dense", ascending=True
            ),
            rank_latest_calls=lambda x: x.groupby(["user1", "date"]).call_time.rank(
                method="dense", ascending=False
            ),
        )
        .query("rank_earliest_calls == 1 or rank_latest_calls == 1")
        .groupby(["user1", "date"])
        .filter(lambda x: x.user2.nunique() == 1)[["user1"]]
        .drop_duplicates()
        .rename(columns={"user1": "user_id"})
    )
