import pandas as pd


def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    cols = ["firstName", "lastName", "city", "state"]
    return person.merge(address, on="personId", how="left")[cols]
