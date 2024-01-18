import numpy as np
import pandas as pd


def market_analysis(
    users: pd.DataFrame, orders: pd.DataFrame, items: pd.DataFrame
) -> pd.DataFrame:
    return (
        orders.assign(rank=orders.groupby("seller_id").order_date.rank())
        .query("rank == 2")
        .merge(items, on="item_id")
        .merge(users, left_on="seller_id", right_on="user_id", how="right")
        .assign(
            second_item_fav_brand=lambda x: np.where(
                x.item_brand == x.favorite_brand, "yes", "no"
            )
        )[["user_id", "second_item_fav_brand"]]
        .rename(
            columns={
                "user_id": "seller_id",
                "second_item_fav_brand": "2nd_item_fav_brand",
            }
        )
    )
