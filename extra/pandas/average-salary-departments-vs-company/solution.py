import numpy as np
import pandas as pd


def average_salary(salary: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:
    return (
        salary.merge(employee, on="employee_id").assign(
            pay_month=lambda x: x.pay_date.dt.strftime("%Y-%m"),
            comp_avg=lambda x: x.groupby("pay_month").amount.transform("mean"),
            dep_avg=lambda x: x.groupby(
                by=["pay_month", "department_id"]
            ).amount.transform("mean"),
            comparison=lambda x: np.where(
                x.dep_avg == x.comp_avg,
                "same",
                np.where(x.dep_avg < x.comp_avg, "lower", "higher"),
            ),
        )
    )[["pay_month", "department_id", "comparison"]].drop_duplicates()
