import pandas as pd


def find_investments(insurance: pd.DataFrame) -> pd.DataFrame:
    return (
        insurance.loc[
            ~insurance.duplicated(subset=["lat", "lon"], keep=False)
            & insurance.duplicated(subset=["tiv_2015"], keep=False),
            ["tiv_2016"],
        ]
        .sum()
        .round(2)
        .to_frame(name="tiv_2016")
    )
