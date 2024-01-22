import pandas as pd


def running_total(scores: pd.DataFrame) -> pd.DataFrame:
    return scores.sort_values(["gender", "day"]).assign(
        total=lambda x: x.groupby("gender").score_points.transform("cumsum")
    )[["gender", "day", "total"]]
