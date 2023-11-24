import pandas as pd


def most_friends(request_accepted: pd.DataFrame) -> pd.DataFrame:
    return (
        pd.concat([request_accepted.requester_id, request_accepted.accepter_id])
        .to_frame(name="id")
        .groupby("id")
        .id.count()
        .reset_index(name="num")
        .sort_values("num", ascending=False)
        .head(1)
    )
