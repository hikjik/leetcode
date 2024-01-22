import pandas as pd


def find_active_users(users: pd.DataFrame) -> pd.DataFrame:
    return (
        users.sort_values("created_at")
        .groupby("user_id")
        .filter(lambda x: (x.created_at.diff() <= pd.Timedelta(days=7)).any())[
            ["user_id"]
        ]
        .drop_duplicates()
    )
