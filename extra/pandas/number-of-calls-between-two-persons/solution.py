import numpy as np
import pandas as pd


def number_of_calls(calls: pd.DataFrame) -> pd.DataFrame:
    return (
        calls.assign(
            person1=lambda x: np.where(x.from_id < x.to_id, x.from_id, x.to_id),
            person2=lambda x: np.where(x.from_id > x.to_id, x.from_id, x.to_id),
        )
        .groupby(by=["person1", "person2"])
        .agg(
            call_count=("duration", "count"),
            total_duration=("duration", sum),
        )
        .reset_index()
    )
