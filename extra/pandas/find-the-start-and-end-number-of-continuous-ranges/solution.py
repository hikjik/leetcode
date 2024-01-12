import pandas as pd


def find_continuous_ranges(logs: pd.DataFrame) -> pd.DataFrame:
    return (
        logs.sort_values(by="log_id")
        .groupby(logs.log_id - logs.index)
        .agg(
            start_id=("log_id", "min"),
            end_id=("log_id", "max"),
        )
    )
