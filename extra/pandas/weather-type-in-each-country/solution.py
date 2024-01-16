import pandas as pd


def weather_type(countries: pd.DataFrame, weather: pd.DataFrame) -> pd.DataFrame:
    def weather_agg(series: pd.Series):
        avg = series.mean()
        if avg >= 25:
            return "Hot"
        if avg <= 15:
            return "Cold"
        return "Warm"

    return (
        weather.query("day.between('2019-11-01', '2019-11-30')")
        .merge(countries, on="country_id")
        .groupby("country_name")
        .weather_state.apply(weather_agg)
        .reset_index(name="weather_type")
    )
