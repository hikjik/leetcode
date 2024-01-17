import pandas as pd


def median_frequency(numbers: pd.DataFrame) -> pd.DataFrame:
    numbers.sort_values("num", inplace=True)
    total = numbers.frequency.sum()
    median = (
        numbers.assign(ps=numbers.frequency.cumsum())
        .query(f"ps - frequency <= {total} / 2 and ps >= {total} / 2")
        .num.mean()
        .round(1)
    )
    return pd.DataFrame({"median": [median]})
