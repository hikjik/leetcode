import pandas as pd


def geography_report(student: pd.DataFrame) -> pd.DataFrame:
    student.sort_values(by="name", inplace=True)
    return pd.concat(
        [
            student.query("continent == 'America'")[["name"]]
            .rename(columns={"name": "America"})
            .reset_index(drop=True),
            student.query("continent == 'Asia'")[["name"]]
            .rename(columns={"name": "Asia"})
            .reset_index(drop=True),
            student.query("continent == 'Europe'")[["name"]]
            .rename(columns={"name": "Europe"})
            .reset_index(drop=True),
        ],
        axis=1,
    )
