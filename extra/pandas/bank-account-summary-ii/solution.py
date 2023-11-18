import pandas as pd


def account_summary(users: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:
    return (
        users.merge(transactions, on="account")
        .groupby("name")
        .amount.sum()
        .reset_index(name="balance")
        .query("balance > 10000")
    )
