import pandas as pd


def is_triangle(triangle: pd.Series) -> bool:
    x, y, z = triangle
    if x + y > z and y + z > x and x + z > y:
        return "Yes"
    return "No"


def triangle_judgement(triangle: pd.DataFrame) -> pd.DataFrame:
    triangle["triangle"] = triangle.apply(is_triangle, axis=1)
    return triangle
