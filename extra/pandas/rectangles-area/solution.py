import pandas as pd


def rectangles_area(points: pd.DataFrame) -> pd.DataFrame:
    return (
        points.merge(points, how="cross", suffixes=["1", "2"])
        .query("id1 < id2 and x_value1 != x_value2 and y_value1 != y_value2")
        .assign(
            area=lambda x: abs(x.x_value1 - x.x_value2) * abs(x.y_value1 - x.y_value2)
        )
        .rename(columns={"id1": "p1", "id2": "p2"})[["p1", "p2", "area"]]
        .sort_values(["area", "p1", "p2"], ascending=[False, True, True])
    )
