import pandas as pd


def form_bond(elements: pd.DataFrame) -> pd.DataFrame:
    return (
        elements.merge(elements, how="cross", suffixes=["_x", "_y"])
        .query("type_x == 'Metal' and type_y == 'Nonmetal'")
        .rename(
            columns={
                "symbol_x": "metal",
                "symbol_y": "nonmetal",
            }
        )[["metal", "nonmetal"]]
    )
