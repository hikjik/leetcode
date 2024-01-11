import pandas as pd


def highest_grade(enrollments: pd.DataFrame) -> pd.DataFrame:
    return enrollments.sort_values(
        by=["student_id", "grade", "course_id"],
        ascending=[True, False, True],
    ).drop_duplicates(subset="student_id")
