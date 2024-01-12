import pandas as pd


def recent_three_orders(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    return (
        customers.merge(orders, on="customer_id")
        .sort_values(
            by=["name", "customer_id", "order_date"],
            ascending=[True, True, False],
        )
        .groupby("customer_id")
        .head(3)
        .rename(columns={"name": "customer_name"})[
            ["customer_name", "customer_id", "order_id", "order_date"]
        ]
    )
