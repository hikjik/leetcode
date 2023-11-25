import pandas as pd


def exchange_seats(seat: pd.DataFrame) -> pd.DataFrame:
    seat.id = seat.id.apply(lambda x: x + 1 if x % 2 == 1 else x - 1)
    if len(seat) % 2 == 1:
        seat.iloc[-1, [seat.columns.get_loc("id")]] = len(seat)
    return seat.sort_values("id")
