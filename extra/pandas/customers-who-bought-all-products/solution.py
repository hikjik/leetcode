import pandas as pd


def find_customers(customer: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    return (
        customer.groupby("customer_id", as_index=False)
        .product_key.nunique()
        .query(f"product_key == {len(product)}")
    )[["customer_id"]]
