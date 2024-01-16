import pandas as pd


def user_activity(activity: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame(
        {
            "average_sessions_per_user": [
                (
                    activity.query("activity_date.between('2019-06-28', '2019-07-27')")
                    .groupby("user_id")
                    .session_id.nunique()
                    .reset_index(name="sessions")
                    .mean()
                    .fillna(0.0)
                    .round(2)
                    .sessions
                )
            ]
        }
    )
