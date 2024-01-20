import pandas as pd


def find_specific_customers(orders: pd.DataFrame) -> pd.DataFrame:
    return (
        orders.assign(year=orders.order_date.dt.year)
        .groupby(["customer_id", "year"])
        .price.sum()
        .reset_index()
        .groupby(["customer_id"])
        .filter(
            lambda x: x.year.max() - x.year.min() + 1
            == (x.year.rank() == x.price.rank()).sum()
        )[["customer_id"]]
        .drop_duplicates()
    )
