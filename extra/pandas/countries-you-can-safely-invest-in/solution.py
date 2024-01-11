import pandas as pd


def find_safe_countries(
    person: pd.DataFrame, country: pd.DataFrame, calls: pd.DataFrame
) -> pd.DataFrame:
    return (
        pd.concat(
            [
                calls,
                calls.rename(
                    columns={"caller_id": "callee_id", "callee_id": "caller_id"}
                ),
            ]
        )
        .rename(columns={"caller_id": "id"})[["id", "duration"]]
        .merge(person, on="id")
        .assign(country_code=lambda x: x.phone_number.str[:3])
        .merge(country.rename(columns={"name": "country"}), on="country_code")
        .groupby("country")
        .filter(lambda x: x.duration.mean() > calls.duration.mean())[["country"]]
        .drop_duplicates()
    )
