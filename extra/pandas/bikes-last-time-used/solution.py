import pandas as pd


def last_used_time(bikes: pd.DataFrame) -> pd.DataFrame:
    return (
        bikes.groupby("bike_number")
        .end_time.max()
        .reset_index()
        .sort_values("end_time", ascending=False)
    )
