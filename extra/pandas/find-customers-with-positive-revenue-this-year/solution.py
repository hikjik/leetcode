import pandas as pd


def find_customers(customers: pd.DataFrame) -> pd.DataFrame:
    return customers.query("year == 2021 and revenue > 0")[["customer_id"]]
