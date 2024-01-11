import pandas as pd


def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    return activity.loc[
        activity.groupby("player_id").event_date.idxmin(),
        ["player_id", "device_id"],
    ]
