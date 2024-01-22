import pandas as pd


def active_businesses(events: pd.DataFrame) -> pd.DataFrame:
    return (
        events.groupby("event_type")
        .occurrences.mean()
        .reset_index(name="avg_occurrences")
        .merge(events, on="event_type")
        .query("occurrences > avg_occurrences")
        .groupby("business_id")
        .event_type.nunique()
        .reset_index()
        .query("event_type > 1")[["business_id"]]
    )
