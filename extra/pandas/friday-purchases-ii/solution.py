import pandas as pd


def friday_purchases(purchases: pd.DataFrame) -> pd.DataFrame:
    return (
        pd.DataFrame(
            {
                "purchase_date": pd.date_range(
                    pd.to_datetime("2023-11-01"),
                    pd.to_datetime("2023-11-30"),
                    freq="d",
                )
            }
        )
        .query("purchase_date.dt.weekday == 4")
        .merge(purchases, on="purchase_date", how="left")
        .fillna(0)
        .groupby("purchase_date")
        .amount_spend.sum()
        .reset_index(name="total_amount")
        .assign(week_of_month=lambda x: range(1, len(x) + 1))[
            ["week_of_month", "purchase_date", "total_amount"]
        ]
    )
