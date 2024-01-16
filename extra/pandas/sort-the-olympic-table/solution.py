import pandas as pd


def sort_table(olympic: pd.DataFrame) -> pd.DataFrame:
    return olympic.sort_values(
        by=["gold_medals", "silver_medals", "bronze_medals", "country"],
        ascending=[False, False, False, True],
    )
