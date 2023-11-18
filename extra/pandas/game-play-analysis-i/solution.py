import pandas as pd


def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    return (
        activity.groupby(by="player_id")
        .event_date.min()
        .reset_index(name="first_login")
    )
