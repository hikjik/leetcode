import pandas as pd


def npv_queries(npv: pd.DataFrame, queries: pd.DataFrame) -> pd.DataFrame:
    return queries.merge(npv, how="left", on=["id", "year"]).fillna(0)
