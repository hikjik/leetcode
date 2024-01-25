import pandas as pd


def airport_with_most_traffic(flights: pd.DataFrame) -> pd.DataFrame:
    return (
        pd.concat(
            [
                flights.rename(columns={"departure_airport": "airport_id"}),
                flights.rename(columns={"arrival_airport": "airport_id"}),
            ]
        )
        .groupby("airport_id")
        .flights_count.sum()
        .reset_index(name="total")
        .query("total == total.max()")[["airport_id"]]
    )
