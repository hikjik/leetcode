import pandas as pd


def consecutive_increasing_transactions(transactions: pd.DataFrame) -> pd.DataFrame:
    return (
        transactions.merge(transactions, on="customer_id")
        .query("amount_x < amount_y")
        .query("(transaction_date_y - transaction_date_x).dt.days == 1")
        .assign(
            rnk=lambda x: x.groupby("customer_id").transaction_date_x.transform("rank"),
            group=lambda x: x.transaction_date_x - pd.to_timedelta(x.rnk, unit="day"),
        )
        .groupby(["customer_id", "group"])
        .agg(
            consecutive_start=("transaction_date_x", "min"),
            consecutive_end=(
                "transaction_date_x",
                lambda x: x.min() + pd.to_timedelta(x.count(), unit="day"),
            ),
        )
        .query("(consecutive_end - consecutive_start).dt.days > 1")
        .reset_index()
        .drop(columns="group")
    )
