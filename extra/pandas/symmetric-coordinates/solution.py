import pandas as pd


def symmetric_pairs(coordinates: pd.DataFrame) -> pd.DataFrame:
    return (
        coordinates.reset_index()
        .merge(
            coordinates.reset_index(),
            left_on=["Y", "X"],
            right_on=["X", "Y"],
            suffixes=["1", "2"],
        )
        .query("index1 != index2 and X1 <= Y1")[["X1", "Y1"]]
        .drop_duplicates()
        .rename(columns={"X1": "x", "Y1": "y"})
        .sort_values(["x", "y"])
    )
