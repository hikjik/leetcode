import pandas as pd


def count_apples_and_oranges(boxes: pd.DataFrame, chests: pd.DataFrame) -> pd.DataFrame:
    df = boxes.merge(chests, on="chest_id", how="left").fillna(0)
    return pd.DataFrame(
        {
            "apple_count": [(df.apple_count_x + df.apple_count_y).sum()],
            "orange_count": [(df.orange_count_x + df.orange_count_y).sum()],
        }
    )
