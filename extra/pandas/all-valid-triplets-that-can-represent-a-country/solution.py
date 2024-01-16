import pandas as pd


def find_valid_triplets(
    school_a: pd.DataFrame, school_b: pd.DataFrame, school_c: pd.DataFrame
) -> pd.DataFrame:
    return (
        school_a.merge(
            school_b,
            how="cross",
            suffixes=["_a", "_b"],
        )
        .merge(
            school_c.add_suffix("_c"),
            how="cross",
        )
        .query("student_name_a != student_name_b")
        .query("student_name_b != student_name_c")
        .query("student_name_c != student_name_a")
        .query("student_id_a != student_id_b")
        .query("student_id_b != student_id_c")
        .query("student_id_c != student_id_a")[
            [
                "student_name_a",
                "student_name_b",
                "student_name_c",
            ]
        ]
        .rename(
            columns={
                "student_name_a": "member_A",
                "student_name_b": "member_B",
                "student_name_c": "member_C",
            }
        )
    )
