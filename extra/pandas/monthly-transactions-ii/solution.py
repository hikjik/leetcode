import numpy as np
import pandas as pd


def monthly_transactions(
    transactions: pd.DataFrame, chargebacks: pd.DataFrame
) -> pd.DataFrame:
    return (
        pd.concat(
            [
                transactions.query("state == 'approved'"),
                transactions.merge(
                    chargebacks,
                    right_on="trans_id",
                    left_on="id",
                    how="right",
                    suffixes=["_x", ""],
                )
                .assign(state="chargeback")
                .drop(columns=["trans_id", "trans_date_x"]),
            ]
        )
        .assign(month=lambda x: x.trans_date.dt.strftime("%Y-%m"))
        .groupby(["month", "country"])
        .apply(
            lambda x: pd.Series(
                {
                    "approved_count": (x.state == "approved").sum(),
                    "approved_amount": np.where(
                        x.state == "approved", x.amount, 0
                    ).sum(),
                    "chargeback_count": (x.state == "chargeback").sum(),
                    "chargeback_amount": np.where(
                        x.state == "chargeback", x.amount, 0
                    ).sum(),
                }
            )
        )
        .reset_index()
    )
