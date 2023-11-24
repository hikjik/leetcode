import pandas as pd


def queries_stats(queries: pd.DataFrame) -> pd.DataFrame:
    return (
        queries.assign(
            quality=queries.rating / queries.position + 1e-9,
            poor_query_percentage=(queries.rating < 3) * 100,
        )
        .groupby("query_name", as_index=False)[["quality", "poor_query_percentage"]]
        .mean()
        .round(2)
    )
