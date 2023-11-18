import pandas as pd


def students_and_examinations(
    students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame
) -> pd.DataFrame:
    return (
        students.merge(subjects, how="cross")
        .merge(
            right=(
                examinations.groupby(["student_id", "subject_name"])
                .subject_name.count()
                .reset_index(name="attended_exams")
            ),
            how="left",
            on=["student_id", "subject_name"],
        )
        .fillna(0)
        .sort_values(by=["student_id", "subject_name"])
    )[["student_id", "student_name", "subject_name", "attended_exams"]]
