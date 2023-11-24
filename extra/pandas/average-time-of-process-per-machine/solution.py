import pandas as pd


def get_average_time(activity: pd.DataFrame) -> pd.DataFrame:
    return (
        pd.merge(
            activity[activity.activity_type == "start"],
            activity[activity.activity_type == "end"],
            on=["machine_id", "process_id"],
            suffixes=["_start", "_end"],
        )
        .groupby("machine_id")
        .apply(lambda x: (x.timestamp_end - x.timestamp_start).mean().round(3))
        .reset_index(name="processing_time")
    )
