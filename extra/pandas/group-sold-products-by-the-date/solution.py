import pandas as pd


def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    return (
        activities.drop_duplicates()
        .groupby(by="sell_date")
        .product.agg(
            [
                ("num_sold", "count"),
                ("products", lambda x: ",".join(sorted(x))),
            ]
        )
        .reset_index()
    )
