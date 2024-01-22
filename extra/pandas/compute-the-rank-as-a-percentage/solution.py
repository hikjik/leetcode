import numpy as np
import pandas as pd


def compute_rating(students: pd.DataFrame) -> pd.DataFrame:
    return students.assign(
        cnt=lambda x: x.groupby("department_id").student_id.transform("count"),
        rnk=lambda x: x.groupby("department_id").mark.rank(
            ascending=False, method="min"
        ),
        percentage=lambda x: np.where(
            x.cnt > 1, ((x.rnk - 1) * 100 / (x.cnt - 1)).round(2), 0
        ),
    )[["student_id", "department_id", "percentage"]]
