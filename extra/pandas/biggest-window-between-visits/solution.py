import pandas as pd


def biggest_window(user_visits: pd.DataFrame) -> pd.DataFrame:
    return (
        user_visits.sort_values(by=["user_id", "visit_date"])
        .assign(
            next_visit=lambda x: x.groupby(by="user_id").visit_date.shift(
                periods=-1, fill_value="2021-01-01"
            ),
            window=lambda x: (x.next_visit - x.visit_date).dt.days,
        )
        .groupby("user_id")
        .window.max()
        .reset_index(name="biggest_window")
    )
