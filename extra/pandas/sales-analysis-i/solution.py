import pandas as pd


def sales_analysis(product: pd.DataFrame, sales: pd.DataFrame) -> pd.DataFrame:
    return (
        sales.groupby("seller_id")
        .price.sum()
        .rank(ascending=False, method="dense")
        .reset_index(name="seller_rank")
        .query("seller_rank == 1")[["seller_id"]]
    )
