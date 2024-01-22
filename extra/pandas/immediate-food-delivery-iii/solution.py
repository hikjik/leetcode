import pandas as pd


def immediate_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    return (
        delivery.groupby("order_date")
        .apply(
            lambda x: 100
            * (x.order_date == x.customer_pref_delivery_date).mean().round(4)
        )
        .reset_index(name="immediate_percentage")
        .sort_values("order_date")
    )
