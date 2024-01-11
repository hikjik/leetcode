import pandas as pd


def customer_order_frequency(
    customers: pd.DataFrame, product: pd.DataFrame, orders: pd.DataFrame
) -> pd.DataFrame:
    return (
        orders.query("order_date.dt.year == 2020")
        .merge(customers, on="customer_id", how="left")
        .merge(product, on="product_id", how="left")
        .assign(cost=lambda x: x.price * x.quantity)
        .groupby("customer_id")
        .filter(
            lambda x: x[x.order_date.dt.month == 6].cost.sum() >= 100
            and x[x.order_date.dt.month == 7].cost.sum() >= 100
        )[["customer_id", "name"]]
        .drop_duplicates()
    )
