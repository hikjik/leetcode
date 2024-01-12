import pandas as pd


def most_recent_orders(
    customers: pd.DataFrame, orders: pd.DataFrame, products: pd.DataFrame
) -> pd.DataFrame:
    return (
        orders.assign(
            rank=orders.groupby("product_id").order_date.rank(
                method="dense", ascending=False
            )
        )
        .query("rank == 1")
        .merge(products, on="product_id")[
            ["product_name", "product_id", "order_id", "order_date"]
        ]
        .sort_values(["product_name", "product_id", "order_id"])
    )
