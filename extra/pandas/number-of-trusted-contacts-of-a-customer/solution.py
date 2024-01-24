import pandas as pd


def count_trusted_contacts(
    customers: pd.DataFrame, contacts: pd.DataFrame, invoices: pd.DataFrame
) -> pd.DataFrame:
    return (
        contacts.merge(customers, left_on="contact_email", right_on="email", how="left")
        .groupby("user_id")
        .agg(contacts_cnt=("user_id", "count"), trusted_contacts_cnt=("email", "count"))
        .reset_index()
        .merge(invoices, on="user_id", how="right")
        .merge(customers, left_on="user_id", right_on="customer_id", how="left")
        .fillna(0)
        .sort_values("invoice_id")[
            [
                "invoice_id",
                "customer_name",
                "price",
                "contacts_cnt",
                "trusted_contacts_cnt",
            ]
        ]
    )
