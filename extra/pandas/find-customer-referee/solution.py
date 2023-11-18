import pandas as pd


def find_customer_referee(customer: pd.DataFrame) -> pd.DataFrame:
    return customer.query("referee_id.isnull() or referee_id != 2")[["name"]]
