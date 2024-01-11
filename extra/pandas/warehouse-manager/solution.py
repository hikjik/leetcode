import pandas as pd


def warehouse_manager(warehouse: pd.DataFrame, products: pd.DataFrame) -> pd.DataFrame:
    return (
        warehouse.merge(products, how="left", on="product_id")
        .groupby("name")
        .apply(lambda x: sum(x.Width * x.Length * x.Height * x.units))
        .reset_index(name="volume")
        .rename(columns={"name": "warehouse_name"})
    )
