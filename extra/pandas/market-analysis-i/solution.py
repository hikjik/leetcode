import pandas as pd


def market_analysis(
    users: pd.DataFrame, orders: pd.DataFrame, items: pd.DataFrame
) -> pd.DataFrame:
    return (
        orders.query("order_date.dt.year==2019")
        .merge(users, left_on="buyer_id", right_on="user_id", how="right")
        .groupby(["user_id", "join_date"])
        .item_id.count()
        .reset_index()
        .rename(columns={"user_id": "buyer_id", "item_id": "orders_in_2019"})
    )
