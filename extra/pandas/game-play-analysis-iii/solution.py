import pandas as pd


def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    activity.sort_values("event_date", inplace=True)
    return activity.assign(
        games_played_so_far=activity.groupby("player_id").games_played.cumsum()
    )[["player_id", "event_date", "games_played_so_far"]]
