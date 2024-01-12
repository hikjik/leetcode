import pandas as pd


def find_quiet_students(student: pd.DataFrame, exam: pd.DataFrame) -> pd.DataFrame:
    return (
        exam.assign(
            high=exam.groupby("exam_id").score.transform("max"),
            low=exam.groupby("exam_id").score.transform("min"),
        )
        .groupby("student_id")
        .filter(lambda x: ((x.low == x.score) | (x.score == x.high)).sum() == 0)
        .merge(student, on="student_id")[["student_id", "student_name"]]
        .sort_values(by="student_id")
        .drop_duplicates()
    )
