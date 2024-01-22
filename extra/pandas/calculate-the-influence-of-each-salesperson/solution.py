import pandas as pd


def calculate_influence(
    salesperson: pd.DataFrame, customer: pd.DataFrame, sales: pd.DataFrame
) -> pd.DataFrame:
    return (
        salesperson.merge(customer, on="salesperson_id", how="left")
        .merge(sales, on="customer_id", how="left")
        .groupby(["salesperson_id", "name"])
        .price.sum()
        .reset_index(name="total")
    )
