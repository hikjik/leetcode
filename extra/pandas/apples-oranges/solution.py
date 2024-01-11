import numpy as np
import pandas as pd


def apples_oranges(sales: pd.DataFrame) -> pd.DataFrame:
    return (
        sales.assign(
            sold_num=np.where(
                sales.fruit == "apples",
                sales.sold_num,
                -sales.sold_num,
            )
        )
        .groupby(by="sale_date")
        .sold_num.sum()
        .reset_index(name="diff")
    )
