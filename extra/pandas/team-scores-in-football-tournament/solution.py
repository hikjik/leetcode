import numpy as np
import pandas as pd


def team_scores(teams: pd.DataFrame, matches: pd.DataFrame) -> pd.DataFrame:
    return (
        pd.concat(
            [
                matches,
                matches.rename(
                    columns={
                        "guest_team": "host_team",
                        "host_team": "guest_team",
                        "guest_goals": "host_goals",
                        "host_goals": "guest_goals",
                    }
                ),
            ],
        )
        .assign(
            num_points=lambda x: np.where(
                x.host_goals > x.guest_goals,
                3,
                np.where(x.host_goals == x.guest_goals, 1, 0),
            )
        )
        .rename(columns={"host_team": "team_id"})[["team_id", "num_points"]]
        .merge(teams, on="team_id", how="right")
        .fillna(0)
        .groupby(by=["team_id", "team_name"])
        .num_points.sum()
        .astype(int)
        .reset_index()
        .sort_values(by=["num_points", "team_id"], ascending=[False, True])
    )
