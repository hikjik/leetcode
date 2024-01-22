import pandas as pd


def find_the_first_day(weather: pd.DataFrame) -> pd.DataFrame:
    return (
        weather.sort_values(
            by=["city_id", "degree", "day"], ascending=[True, False, True]
        )
        .groupby("city_id")
        .head(1)
    )
