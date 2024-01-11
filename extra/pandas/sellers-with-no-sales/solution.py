import pandas as pd


def sellers_with_no_sales(
    customer: pd.DataFrame, orders: pd.DataFrame, seller: pd.DataFrame
) -> pd.DataFrame:
    return seller[
        ~seller.seller_id.isin(orders[orders.sale_date.dt.year == 2020].seller_id)
    ][["seller_name"]].sort_values(by="seller_name", ascending=True)
