import pandas as pd


def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    ids = (
        orders.groupby("customer_id")
        .filter(
            lambda x: (x.product_name == "A").any()
            and (x.product_name == "B").any()
            and (x.product_name != "C").all()
        )
        .customer_id
    )
    return customers[customers.customer_id.isin(ids)].sort_values(by="customer_id")
