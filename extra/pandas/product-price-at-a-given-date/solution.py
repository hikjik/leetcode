import pandas as pd


def price_at_given_date(products: pd.DataFrame) -> pd.DataFrame:
    return (
        products.query("change_date <= '2019-08-16'")
        .sort_values(by=["product_id", "change_date"], ascending=[True, False])
        .drop_duplicates(subset=["product_id"], keep="first")
        .merge(products[["product_id"]].drop_duplicates(), how="right")
        .fillna(10)
        .rename(columns={"new_price": "price"})[["product_id", "price"]]
    )
