import pandas as pd


def analyze_products(product: pd.DataFrame, invoice: pd.DataFrame) -> pd.DataFrame:
    return (
        product.merge(invoice, how="left")
        .groupby("name")
        .sum()
        .reset_index()
        .drop(columns=["product_id", "invoice_id"])
        .sort_values(by="name")
    )
