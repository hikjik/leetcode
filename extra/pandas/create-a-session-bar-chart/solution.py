import pandas as pd


def create_bar_chart(sessions: pd.DataFrame) -> pd.DataFrame:
    return (
        pd.cut(
            sessions.duration,
            labels=["[0-5>", "[5-10>", "[10-15>", "15 or more"],
            bins=[0, 300, 600, 900, float("inf")],
        )
        .value_counts()
        .reset_index(name="total")
        .rename(columns={"duration": "bin"})
    )
