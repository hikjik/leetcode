import pandas as pd


def grand_slam_titles(
    players: pd.DataFrame, championships: pd.DataFrame
) -> pd.DataFrame:
    return (
        championships.drop(columns=["year"])
        .melt(value_name="player_id", var_name="grand_slams_count")
        .groupby("player_id")
        .count()
        .reset_index()
        .merge(players, on="player_id")
    )
