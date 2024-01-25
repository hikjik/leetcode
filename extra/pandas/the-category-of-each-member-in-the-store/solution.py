import pandas as pd


def find_categories(
    members: pd.DataFrame, visits: pd.DataFrame, purchases: pd.DataFrame
) -> pd.DataFrame:
    return (
        members.merge(visits, on="member_id", how="left")
        .merge(purchases, on="visit_id", how="left")
        .groupby(["member_id", "name"])
        .apply(lambda x: x.charged_amount.count() * 100 / x.visit_date.count())
        .fillna(-1)
        .reset_index(name="conversion_rate")
        .assign(
            category=lambda x: pd.cut(
                x.conversion_rate,
                bins=[-1, 0, 50, 80, 101],
                labels=["Bronze", "Silver", "Gold", "Diamond"],
                right=False,
                include_lowest=True,
            )
        )
        .drop(columns="conversion_rate")
    )
