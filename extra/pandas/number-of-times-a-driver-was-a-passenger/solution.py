import pandas as pd


def driver_passenger(rides: pd.DataFrame) -> pd.DataFrame:
    return (
        rides.merge(
            rides,
            left_on="driver_id",
            right_on="passenger_id",
            how="left",
            suffixes=["", "_y"],
        )
        .groupby("driver_id")
        .ride_id_y.nunique()
        .reset_index(name="cnt")
    )
