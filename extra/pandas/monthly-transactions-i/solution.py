import numpy as np
import pandas as pd


def monthly_transactions(transactions: pd.DataFrame) -> pd.DataFrame:
    return (
        transactions.assign(
            month=transactions.trans_date.dt.strftime("%Y-%m"),
            approved=transactions.apply(
                lambda x: x.amount if x.state == "approved" else None,
                axis=1,
            ),
        )
        .groupby(["month", "country"], as_index=False)
        .agg(
            trans_count=("state", "count"),
            approved_count=("approved", "count"),
            trans_total_amount=("amount", "sum"),
            approved_total_amount=("approved", "sum"),
        )
    )
