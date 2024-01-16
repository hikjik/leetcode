import pandas as pd


def sales_analysis(product: pd.DataFrame, sales: pd.DataFrame) -> pd.DataFrame:
    return (
        sales.merge(product, on="product_id")
        .groupby("buyer_id")
        .filter(
            lambda x: (x.product_name == "iPhone").sum() == 0
            and (x.product_name == "S8").sum() > 0
        )[["buyer_id"]]
        .drop_duplicates()
    )
