import pandas as pd


def find_all_matches(teams: pd.DataFrame) -> pd.DataFrame:
    return (
        teams.merge(teams, how="cross")
        .query("team_name_x != team_name_y")
        .rename(
            columns={
                "team_name_x": "home_team",
                "team_name_y": "away_team",
            }
        )
    )
