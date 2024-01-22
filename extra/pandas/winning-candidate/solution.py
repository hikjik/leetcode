import pandas as pd


def winning_candidate(candidate: pd.DataFrame, vote: pd.DataFrame) -> pd.DataFrame:
    return (
        vote.groupby("candidateId")
        .id.count()
        .rank(ascending=False)
        .reset_index(name="rnk")
        .query("rnk == 1")
        .merge(candidate, left_on="candidateId", right_on="id")[["name"]]
    )
