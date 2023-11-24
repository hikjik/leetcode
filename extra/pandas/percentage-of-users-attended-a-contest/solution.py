import pandas as pd


def users_percentage(users: pd.DataFrame, register: pd.DataFrame) -> pd.DataFrame:
    return (
        register.groupby("contest_id")
        .user_id.apply(lambda x: round(len(x) * 100 / len(users), 2))
        .reset_index(name="percentage")
        .sort_values(by=["percentage", "contest_id"], ascending=[False, True])
    )
