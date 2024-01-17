import pandas as pd


def sales_by_day(orders: pd.DataFrame, items: pd.DataFrame) -> pd.DataFrame:
    weekdays = pd.CategoricalDtype(
        categories=[
            "MONDAY",
            "TUESDAY",
            "WEDNESDAY",
            "THURSDAY",
            "FRIDAY",
            "SATURDAY",
            "SUNDAY",
        ],
        ordered=True,
    )

    return (
        items.merge(orders, how="left", on="item_id")
        .rename(columns={"item_category": "CATEGORY"})
        .assign(
            weekday=lambda x: x.order_date.dt.day_name().str.upper().astype(weekdays)
        )
        .pivot_table(
            index="CATEGORY", columns="weekday", values="quantity", aggfunc="sum"
        )
        .reset_index()
    )
