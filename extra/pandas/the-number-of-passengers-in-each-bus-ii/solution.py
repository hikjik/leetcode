import pandas as pd


def number_of_passengers(buses: pd.DataFrame, passengers: pd.DataFrame) -> pd.DataFrame:
    df = (
        buses.merge(passengers, how="cross")
        .query("arrival_time_y <= arrival_time_x")
        .sort_values("arrival_time_x")
        .groupby("bus_id")
        .passenger_id.count()
        .reset_index(name="passengers_cnt")
        .merge(buses, on="bus_id", how="right")
        .fillna(0)
    )

    for i in range(len(df)):
        if i:
            df.loc[i, "passengers_cnt"] = min(
                df.loc[i, "passengers_cnt"] - df.loc[i - 1, "cnt"],
                df.loc[i, "capacity"],
            )
            df.loc[i, "cnt"] = df.loc[i, "passengers_cnt"] + df.loc[i - 1, "cnt"]
        else:
            df.loc[i, "passengers_cnt"] = min(
                df.loc[i, "passengers_cnt"],
                df.loc[i, "capacity"],
            )
            df.loc[i, "cnt"] = df.loc[i, "passengers_cnt"]

    return df[["bus_id", "passengers_cnt"]].sort_values("bus_id")
