import pandas as pd


def count_turned_streamers(sessions: pd.DataFrame) -> pd.DataFrame:
    return (
        sessions.assign(
            sessions_count=sessions.groupby("user_id").session_type.transform(
                lambda x: (x == "Streamer").sum(),
            ),
            rank=sessions.groupby("user_id").session_start.rank(),
        )
        .query("rank == 1 and session_type == 'Viewer' and sessions_count > 0")[
            ["user_id", "sessions_count"]
        ]
        .sort_values(["sessions_count", "user_id"], ascending=[False, False])
    )
