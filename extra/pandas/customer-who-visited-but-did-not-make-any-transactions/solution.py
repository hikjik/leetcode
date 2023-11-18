import pandas as pd


def find_customers(visits: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:
    return (
        visits.merge(transactions, on="visit_id", how="left")
        .query("transaction_id.isnull()")
        .groupby("customer_id")
        .customer_id.count()
        .reset_index(name="count_no_trans")
    )
