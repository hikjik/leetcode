import pandas as pd


def count_students(student: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    return (
        department.merge(student, on="dept_id", how="left")
        .groupby("dept_name")
        .student_id.count()
        .reset_index(name="student_number")
        .sort_values(["student_number", "dept_name"], ascending=[False, True])
    )
