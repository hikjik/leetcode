import pandas as pd


def list_products(products: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    return (
        orders[orders.order_date.between("2020-02-01", "2020-02-29")]
        .merge(products, on="product_id")
        .groupby("product_name", as_index=False)
        .unit.sum()
        .query("unit >= 100")
    )
