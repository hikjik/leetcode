import pandas as pd


def consecutive_available_seats(cinema: pd.DataFrame) -> pd.DataFrame:
    free_seats = cinema.query("free == 1").sort_values(by="seat_id")[["seat_id"]]
    return free_seats.query(
        "seat_id.shift(1) == seat_id - 1 or seat_id + 1 == seat_id.shift(-1)"
    )
