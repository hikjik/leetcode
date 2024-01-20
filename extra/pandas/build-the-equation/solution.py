import numpy as np
import pandas as pd


def build_the_equation(terms: pd.DataFrame) -> pd.DataFrame:
    equation = (
        terms.assign(
            term=(
                np.where(terms.factor > 0, "+", "")
                + terms.factor.astype(str)
                + np.where(
                    terms.power == 0,
                    "",
                    np.where(terms.power == 1, "X", "X^" + terms.power.astype(str)),
                )
            ),
        )
        .sort_values("power", ascending=False)
        .term.sum()
        + "=0"
    )
    return pd.DataFrame({"equation": [equation]})
