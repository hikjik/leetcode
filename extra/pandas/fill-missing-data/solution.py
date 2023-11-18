import pandas as pd


def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    return products.assign(quantity=products.quantity.fillna(0))
