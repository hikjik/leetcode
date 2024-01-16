import pandas as pd


def acceptance_rate(
    friend_request: pd.DataFrame, request_accepted: pd.DataFrame
) -> pd.DataFrame:
    requests = friend_request.drop_duplicates(
        subset=["sender_id", "send_to_id"],
    ).shape[0]
    accepts = request_accepted.drop_duplicates(
        subset=["requester_id", "accepter_id"],
    ).shape[0]
    accept_rate = round(accepts / requests, 2) if requests else 0
    return pd.DataFrame({"accept_rate": [accept_rate]})
