import pandas as pd


def average_selling_price(
    prices: pd.DataFrame, units_sold: pd.DataFrame
) -> pd.DataFrame:
    return (
        prices.merge(units_sold, on="product_id", how="left")
        .query("purchase_date.between(start_date, end_date) or purchase_date.isnull()")
        .groupby("product_id")
        .apply(lambda x: sum(x.price * x.units) / sum(x.units))
        .fillna(0)
        .round(2)
        .to_frame("average_price")
        .reset_index()
    )
