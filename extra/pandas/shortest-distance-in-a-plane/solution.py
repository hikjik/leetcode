import pandas as pd


def shortest_distance(point2_d: pd.DataFrame) -> pd.DataFrame:
    min_distance = (
        point2_d.merge(point2_d, how="cross", suffixes=["1", "2"])
        .assign(
            dist=lambda df: ((df.x1 - df.x2).pow(2) + (df.y1 - df.y2).pow(2)).pow(0.5)
        )
        .query("dist != 0")
        .dist.min()
        .round(2)
    )
    return pd.DataFrame({"shortest": [min_distance]})
