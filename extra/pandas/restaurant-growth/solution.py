import pandas as pd


def restaurant_growth(customer: pd.DataFrame) -> pd.DataFrame:
    return (
        customer.groupby("visited_on")
        .amount.sum()
        .rolling(7)
        .agg({"amount": "sum", "average_amount": "mean"})
        .round(2)
        .dropna()
        .reset_index()
    )
