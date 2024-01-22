import pandas as pd


def unpopular_books(books: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    books = books[books.available_from + pd.Timedelta(days=30) < "2019-06-23"]
    orders = orders[orders.dispatch_date + pd.Timedelta(days=365) > "2019-06-23"]
    return (
        books.merge(orders, on="book_id", how="left")
        .groupby(["book_id", "name"])
        .quantity.sum()
        .reset_index(name="sales_count")
        .query("sales_count < 10")
        .drop(columns="sales_count")
    )
