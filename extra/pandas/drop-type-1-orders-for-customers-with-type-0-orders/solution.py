import pandas as pd


def drop_specific_orders(orders: pd.DataFrame) -> pd.DataFrame:
    return (
        orders.assign(
            rnk=orders.groupby("customer_id").order_type.transform(
                lambda x: x.rank(method="min")
            )
        )
        .query("rnk == 1")
        .drop(columns="rnk")
    )
