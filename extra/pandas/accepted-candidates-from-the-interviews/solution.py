import pandas as pd


def accepted_candidates(candidates: pd.DataFrame, rounds: pd.DataFrame) -> pd.DataFrame:
    return candidates.merge(
        rounds.groupby("interview_id").score.sum(), on="interview_id"
    ).query("years_of_exp >= 2 and score > 15")[["candidate_id"]]
