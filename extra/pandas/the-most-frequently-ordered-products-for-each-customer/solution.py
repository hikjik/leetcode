import pandas as pd


def most_frequently_products(
    customers: pd.DataFrame, orders: pd.DataFrame, products: pd.DataFrame
) -> pd.DataFrame:
    return (
        orders.groupby(by=["customer_id", "product_id"])
        .product_id.count()
        .reset_index(name="product_count")
        .assign(
            rank=lambda x: x.groupby(by="customer_id")
            .product_count.rank(method="dense", ascending=False)
            .astype(int)
        )
        .query("rank == 1")
        .merge(products, on="product_id")[["customer_id", "product_id", "product_name"]]
    )
