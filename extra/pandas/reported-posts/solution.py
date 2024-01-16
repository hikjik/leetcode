import pandas as pd


def reported_posts(actions: pd.DataFrame) -> pd.DataFrame:
    return (
        actions.query(
            "action_date == '2019-07-04' and action == 'report' and not extra.isnull()"
        )
        .groupby("extra")
        .post_id.nunique()
        .reset_index(name="report_count")
        .rename(columns={"extra": "report_reason"})
    )
