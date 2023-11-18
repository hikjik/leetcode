import pandas as pd


def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    courses = courses["class"].value_counts().reset_index()
    return courses[courses["count"] >= 5][["class"]]
