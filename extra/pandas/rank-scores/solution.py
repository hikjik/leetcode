import pandas as pd


def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores.sort_values("score", ascending=False, inplace=True)
    scores["rank"] = scores.score.rank(method="dense", ascending=False)
    return scores[["score", "rank"]]
