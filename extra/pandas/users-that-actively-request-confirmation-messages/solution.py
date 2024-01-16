import pandas as pd


def find_requesting_users(
    signups: pd.DataFrame, confirmations: pd.DataFrame
) -> pd.DataFrame:
    return (
        confirmations.merge(confirmations, on="user_id")
        .query("time_stamp_x < time_stamp_y")
        .query("(time_stamp_y - time_stamp_x).dt.total_seconds() <= 24 * 60 * 60")[
            ["user_id"]
        ]
        .drop_duplicates()
    )
