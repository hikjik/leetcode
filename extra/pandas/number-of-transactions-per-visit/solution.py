import pandas as pd


def draw_chart(visits: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:
    users_transactions = (
        visits.merge(
            transactions,
            left_on=["visit_date", "user_id"],
            right_on=["transaction_date", "user_id"],
            how="left",
        )
        .groupby(["visit_date", "user_id"])
        .amount.count()
        .reset_index(name="transactions_count")
        .groupby("transactions_count")
        .user_id.count()
        .reset_index(name="visits_count")
    )

    return (
        pd.DataFrame(
            {
                "transactions_count": range(
                    max(users_transactions.transactions_count) + 1
                )
            }
        )
        .merge(users_transactions, on="transactions_count", how="left")
        .fillna(0)
    )
