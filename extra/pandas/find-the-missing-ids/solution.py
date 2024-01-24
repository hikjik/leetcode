import pandas as pd


def find_missing_ids(customers: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame(
        {
            "ids": list(
                set(range(1, customers.customer_id.max())).difference(
                    customers.customer_id
                )
            )
        }
    )
