import pandas as pd


def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    users = users[users.banned == "No"]
    ans = (
        trips[
            trips.request_at.between("2013-10-01", "2013-10-03")
            & trips.client_id.isin(users.users_id)
            & trips.driver_id.isin(users.users_id)
        ]
        .groupby("request_at")
        .apply(
            lambda group: pd.Series(
                {"Cancellation Rate": (group.status != "completed").mean().round(2)}
            )
        )
    )
    if ans.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])
    return ans.reset_index().rename(columns={"request_at": "Day"})
