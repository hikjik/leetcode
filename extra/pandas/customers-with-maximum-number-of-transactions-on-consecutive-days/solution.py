import pandas as pd


def find_customers(transactions: pd.DataFrame) -> pd.DataFrame:
    return (
        transactions.sort_values(by=["customer_id", "transaction_date"])
        .assign(
            rnk=transactions.groupby("customer_id").transaction_date.rank(),
            group=lambda x: x.transaction_date - pd.to_timedelta(x.rnk, unit="d"),
        )
        .groupby(["customer_id", "group"])
        .transaction_id.nunique()
        .reset_index(name="customer_rank")
        .query("customer_rank == customer_rank.max()")
        .sort_values("customer_id")[["customer_id"]]
    )
