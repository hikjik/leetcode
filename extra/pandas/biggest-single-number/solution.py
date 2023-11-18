import pandas as pd


def biggest_single_number(my_numbers: pd.DataFrame) -> pd.DataFrame:
    return my_numbers.drop_duplicates(keep=False).max().to_frame(name="num")
