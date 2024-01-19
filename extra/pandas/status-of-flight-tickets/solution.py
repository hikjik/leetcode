import numpy as np
import pandas as pd


def ticket_status(flights: pd.DataFrame, passengers: pd.DataFrame) -> pd.DataFrame:
    return (
        passengers.assign(rnk=passengers.groupby("flight_id").booking_time.rank())
        .merge(flights, on="flight_id")
        .assign(
            Status=lambda x: np.where(x.rnk <= x.capacity, "Confirmed", "Waitlist")
        )[["passenger_id", "Status"]]
        .sort_values("passenger_id")
    )
