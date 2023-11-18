import pandas as pd


def sales_person(
    sales_person: pd.DataFrame,
    company: pd.DataFrame,
    orders: pd.DataFrame,
) -> pd.DataFrame:
    return sales_person[
        ~sales_person.sales_id.isin(
            orders.merge(right=company[company.name == "RED"], on="com_id").sales_id
        )
    ][["name"]]
