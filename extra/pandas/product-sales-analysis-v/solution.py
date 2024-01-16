import pandas as pd


def product_sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    return (
        sales.merge(product, on="product_id")
        .groupby("user_id")
        .apply(lambda x: (x.quantity * x.price).sum())
        .reset_index(name="spending")
        .sort_values(by=["spending", "user_id"], ascending=[False, True])
    )
