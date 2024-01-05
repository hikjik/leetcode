import pandas as pd


def food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    percentage = (
        delivery.customer_pref_delivery_date == delivery.order_date
    ).mean() * 100
    return pd.DataFrame({"immediate_percentage": [percentage.round(2)]})
