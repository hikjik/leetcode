import pandas as pd


def count_occurrences(files: pd.DataFrame) -> pd.DataFrame:
    bull = files.content.str.contains(" bull ", case=False).sum()
    bear = files.content.str.contains(" bear ", case=False).sum()
    return pd.DataFrame(
        {
            "word": ["bull", "bear"],
            "count": [bull, bear],
        }
    )
