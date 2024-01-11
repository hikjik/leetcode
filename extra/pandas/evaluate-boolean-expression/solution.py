import numpy as np
import pandas as pd


def eval_expression(variables: pd.DataFrame, expressions: pd.DataFrame) -> pd.DataFrame:
    return (
        expressions.merge(
            variables,
            left_on="left_operand",
            right_on="name",
        )
        .merge(
            variables,
            left_on="right_operand",
            right_on="name",
            suffixes=["_l", "_r"],
        )
        .assign(
            value=lambda x: np.where(
                x.operator == "=",
                x.value_l == x.value_r,
                np.where(
                    x.operator == ">",
                    x.value_l > x.value_r,
                    x.value_l < x.value_r,
                ),
            )
        )
        .assign(
            value=lambda x: x.value.replace(
                {
                    True: "true",
                    False: "false",
                }
            ),
        )[["left_operand", "operator", "right_operand", "value"]]
    )
