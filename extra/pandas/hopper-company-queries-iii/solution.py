import pandas as pd


def hopper_company_queries(
    drivers: pd.DataFrame, rides: pd.DataFrame, accepted_rides: pd.DataFrame
) -> pd.DataFrame:
    month = pd.DataFrame({"month": range(1, 13)})

    accepted_rides = (
        rides.merge(accepted_rides, on="ride_id", how="inner")
        .query("requested_at.dt.year == 2020")
        .assign(month=lambda x: x.requested_at.dt.month)
        .merge(month, on="month", how="right")
        .groupby("month")
        .agg(
            average_ride_distance=("ride_distance", "sum"),
            average_ride_duration=("ride_duration", "sum"),
        )
        .reset_index()
    )

    return (
        month.merge(accepted_rides, on="month", how="left")
        .rolling(3, on="month")
        .mean()
        .round(2)
        .fillna(0)
        .assign(month=lambda x: x.month - 2)
        .query("month > 0")
    )
