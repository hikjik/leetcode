import pandas as pd


def tournament_winners(players: pd.DataFrame, matches: pd.DataFrame) -> pd.DataFrame:
    return (
        pd.concat(
            [
                matches[["first_player", "first_score"]].rename(
                    columns={"first_player": "player_id", "first_score": "score"}
                ),
                matches[["second_player", "second_score"]].rename(
                    columns={"second_player": "player_id", "second_score": "score"}
                ),
            ]
        )
        .groupby("player_id")
        .score.sum()
        .reset_index()
        .merge(players, on="player_id", how="right")
        .fillna(0)
        .sort_values(["score", "player_id"], ascending=[False, True])
        .groupby("group_id")
        .head(1)
        .drop(columns="score")
    )
