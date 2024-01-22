import pandas as pd


def rolling_average(steps: pd.DataFrame) -> pd.DataFrame:
    return (
        steps.sort_values(["user_id", "steps_date"])
        .set_index("steps_date")
        .groupby("user_id")
        .steps_count.rolling("3D", min_periods=3)
        .mean()
        .round(2)
        .reset_index(name="rolling_average")
        .dropna()
    )
