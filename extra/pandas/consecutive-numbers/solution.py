import pandas as pd


def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    nunique = logs.num.rolling(window=3).apply(lambda x: x.nunique())
    return pd.DataFrame({"ConsecutiveNums": logs[nunique == 1].num.unique()})
