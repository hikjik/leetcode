import pandas as pd


def count_comments(submissions: pd.DataFrame) -> pd.DataFrame:
    return (
        submissions.drop_duplicates()
        .query("parent_id.isnull()")
        .merge(
            submissions,
            how="left",
            left_on="sub_id",
            right_on="parent_id",
            suffixes=["_post", "_comment"],
        )
        .rename(columns={"sub_id_post": "post_id"})
        .groupby("post_id")
        .sub_id_comment.nunique()
        .reset_index(name="number_of_comments")
        .sort_values(by="post_id")
    )
