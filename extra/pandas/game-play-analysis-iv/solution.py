import pandas as pd


def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    fraction = (
        activity.groupby("player_id")
        .event_date.min()
        .reset_index(name="signup")
        .merge(activity, on="player_id")
        .query("(event_date - signup).dt.days == 1")
        .player_id.count()
        / activity.player_id.nunique()
    ).round(2)
    return pd.DataFrame({"fraction": [fraction]})
