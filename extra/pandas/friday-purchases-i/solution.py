import pandas as pd


def friday_purchases(purchases: pd.DataFrame) -> pd.DataFrame:
    return (
        purchases.query("purchase_date.dt.weekday == 4")
        .assign(week_of_month=lambda x: (x.purchase_date.dt.day - 1) // 7 + 1)
        .groupby(["week_of_month", "purchase_date"])
        .amount_spend.sum()
        .reset_index(name="total_amount")
        .sort_values("week_of_month")
    )
