import pandas as pd


def capital_gainloss(stocks: pd.DataFrame) -> pd.DataFrame:
    stocks["price"] = stocks.apply(
        lambda x: -x.price if x.operation == "Buy" else x.price, axis=1
    )
    return (
        stocks.groupby(by="stock_name")
        .price.sum()
        .reset_index(name="capital_gain_loss")
    )
