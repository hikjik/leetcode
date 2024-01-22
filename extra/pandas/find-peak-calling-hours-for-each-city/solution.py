import pandas as pd


def peak_calling_hours(calls: pd.DataFrame) -> pd.DataFrame:
    return (
        calls.assign(hour=calls.call_time.dt.hour)
        .groupby(["city", "hour"])
        .call_time.count()
        .reset_index(name="number_of_calls")
        .assign(
            rank=lambda x: x.groupby("city").number_of_calls.rank(
                ascending=False, method="dense"
            )
        )
        .query("rank == 1")
        .drop(columns="rank")
        .rename(columns={"hour": "peak_calling_hour"})
        .sort_values(["peak_calling_hour", "city"], ascending=[False, False])
    )
