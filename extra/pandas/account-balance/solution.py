import numpy as np
import pandas as pd


def account_balance(transactions: pd.DataFrame) -> pd.DataFrame:
    return transactions.sort_values(["account_id", "day"]).assign(
        amount=lambda x: np.where(x.type == "Deposit", x.amount, -x.amount).astype(int),
        balance=lambda x: x.groupby("account_id").amount.cumsum(),
    )[["account_id", "day", "balance"]]
