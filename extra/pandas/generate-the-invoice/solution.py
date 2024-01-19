import pandas as pd


def generate_the_invoice(
    products: pd.DataFrame, purchases: pd.DataFrame
) -> pd.DataFrame:
    return (
        purchases.merge(products, on="product_id")
        .assign(total_price=lambda x: x.price * x.quantity)
        .groupby("invoice_id")
        .total_price.sum()
        .rank(ascending=False, method="first")
        .reset_index(name="rnk")
        .query("rnk == 1")
        .merge(purchases, on="invoice_id")
        .merge(products, on="product_id")
        .assign(price=lambda x: x.price * x.quantity)[
            ["product_id", "quantity", "price"]
        ]
    )
