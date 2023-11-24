import pandas as pd


def human_traffic(stadium: pd.DataFrame) -> pd.DataFrame:
    stadium = stadium[stadium.people >= 100]
    flag = (stadium.id.diff() == 1) & (stadium.id.diff().shift(1) == 1)
    return stadium[flag | flag.shift(-1) | flag.shift(-2)]
