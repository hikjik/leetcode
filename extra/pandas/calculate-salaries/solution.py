import numpy as np
import pandas as pd


def calculate_salaries(salaries: pd.DataFrame) -> pd.DataFrame:
    return (
        salaries.groupby("company_id")
        .apply(
            lambda x: np.where(
                x.salary.max() < 1000,
                0.0,
                np.where(x.salary.max() <= 10000, 0.24, 0.49),
            )
        )
        .reset_index(name="tax")
        .merge(salaries, on="company_id")
        .assign(salary=lambda x: (x.salary - x.tax * x.salary + 0.5).astype(int))
        .drop(columns="tax")
    )
