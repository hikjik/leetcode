import pandas as pd


def orders_above_average(orders_details: pd.DataFrame) -> pd.DataFrame:
    max_avg_quantity = orders_details.groupby("order_id").quantity.mean().max()
    return orders_details.query("quantity > @max_avg_quantity")[
        ["order_id"]
    ].drop_duplicates()
