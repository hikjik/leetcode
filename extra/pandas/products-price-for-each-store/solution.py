import pandas as pd


def products_price(products: pd.DataFrame) -> pd.DataFrame:
    return products.pivot(
        index="product_id", columns="store", values="price"
    ).reset_index()
