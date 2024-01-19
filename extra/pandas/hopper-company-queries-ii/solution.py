import numpy as np
import pandas as pd


def hopper_company_queries(
    drivers: pd.DataFrame, rides: pd.DataFrame, accepted_rides: pd.DataFrame
) -> pd.DataFrame:
    month = pd.DataFrame({"month": range(1, 13)})

    active_drivers = (
        drivers.query("join_date.dt.year <= 2020")
        .assign(
            month=lambda x: np.where(
                x.join_date.dt.year == 2020, x.join_date.dt.month, 1
            )
        )
        .merge(month, on="month", how="right")
        .groupby("month")
        .driver_id.nunique()
        .cumsum()
        .reset_index(name="active_drivers")
    )

    accepted_rides = (
        rides.merge(accepted_rides, on="ride_id", how="inner")
        .query("requested_at.dt.year == 2020")
        .assign(month=lambda x: x.requested_at.dt.month)
        .merge(month, on="month", how="right")
        .groupby("month")
        .driver_id.nunique()
        .reset_index(name="accepted_rides")
    )

    return (
        active_drivers.merge(accepted_rides, on="month")
        .assign(
            working_percentage=lambda x: (x.accepted_rides / x.active_drivers * 100)
        )
        .round(2)
        .fillna(0)
        .drop(columns=["accepted_rides", "active_drivers"])
    )
