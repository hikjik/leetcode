import pandas as pd


def count_occurrences(spotify: pd.DataFrame) -> pd.DataFrame:
    return (
        spotify.groupby("artist")
        .id.count()
        .reset_index(name="occurrences")
        .sort_values(by=["occurrences", "artist"], ascending=[False, True])
    )
