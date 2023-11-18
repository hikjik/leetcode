import datetime

import pandas as pd


def reformat_table(department: pd.DataFrame) -> pd.DataFrame:
    months = [datetime.date(1900, i, 1).strftime("%b") for i in range(1, 13)]
    new_columns = ["id"] + [f"{m}_Revenue" for m in months]
    return (
        department.pivot(index="id", columns="month", values="revenue")
        .add_suffix("_Revenue")
        .reset_index()
        .reindex(columns=new_columns)
    )
