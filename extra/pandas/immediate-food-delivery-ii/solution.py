import pandas as pd


def immediate_food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    first_orders = delivery.groupby("customer_id", as_index=False).min()
    immediate_orders = first_orders.query("order_date == customer_pref_delivery_date")
    percentage = round(len(immediate_orders) / len(first_orders) * 100, 2)
    return pd.DataFrame({"immediate_percentage": [percentage]})
