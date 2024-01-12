import pandas as pd


def find_maximum_transaction(transactions: pd.DataFrame) -> pd.DataFrame:
    return (
        transactions.assign(
            rank=transactions.assign(day=transactions.day.dt.to_period("D"))
            .groupby(by="day")["amount"]
            .rank(method="dense", ascending=False)
            .astype(int)
        )
        .query("rank == 1")
        .sort_values(by="transaction_id")[["transaction_id"]]
    )
