import pandas as pd


def ad_free_sessions(playback: pd.DataFrame, ads: pd.DataFrame) -> pd.DataFrame:
    return playback.loc[
        ~playback.session_id.isin(
            playback.merge(ads, on="customer_id")
            .query("timestamp.between(start_time, end_time)")
            .session_id
        ),
        ["session_id"],
    ]
