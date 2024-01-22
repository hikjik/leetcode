import pandas as pd


def product_sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    return (
        sales.merge(product, on="product_id")
        .groupby(["user_id", "product_id"])
        .apply(lambda x: (x.price * x.quantity).sum())
        .reset_index(name="spend")
        .assign(
            rnk=lambda x: x.groupby("user_id").spend.rank(
                ascending=False, method="dense"
            )
        )
        .query("rnk == 1")[["user_id", "product_id"]]
    )
