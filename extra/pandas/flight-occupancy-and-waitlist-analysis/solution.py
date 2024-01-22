import pandas as pd


def waitlist_analysis(flights: pd.DataFrame, passengers: pd.DataFrame) -> pd.DataFrame:
    return (
        flights.merge(passengers, on="flight_id", how="left")
        .groupby("flight_id")
        .apply(
            lambda x: pd.Series(
                {
                    "booked_cnt": min(x.passenger_id.count(), min(x.capacity)),
                    "waitlist_cnt": max(0, x.passenger_id.count() - min(x.capacity)),
                },
            )
        )
        .reset_index()
        .sort_values("flight_id")
    )

