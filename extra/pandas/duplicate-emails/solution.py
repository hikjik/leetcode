import pandas as pd


def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    return (
        person.groupby(by="email")
        .filter(lambda x: len(x) > 1)[["email"]]
        .drop_duplicates()
    )
