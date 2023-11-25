import pandas as pd


def last_passenger(queue: pd.DataFrame) -> pd.DataFrame:
    queue.sort_values("turn", inplace=True)
    return queue[queue.weight.cumsum() <= 1000].tail(1)[["person_name"]]
