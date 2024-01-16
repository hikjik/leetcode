import pandas as pd


def fix_name_format(sales: pd.DataFrame) -> pd.DataFrame:
    return (
        sales.assign(
            sale_date=sales.sale_date.apply(lambda x: x.strftime("%Y-%m")),
            product_name=sales.product_name.apply(lambda x: x.lower().strip()),
        )
        .groupby(by=["product_name", "sale_date"])
        .sale_id.count()
        .reset_index(name="total")
    )
