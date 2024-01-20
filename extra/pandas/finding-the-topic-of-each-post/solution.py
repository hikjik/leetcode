import re

import pandas as pd


def find_topic(keywords: pd.DataFrame, posts: pd.DataFrame) -> pd.DataFrame:
    return (
        keywords.merge(posts, how="cross")
        .assign(
            match=lambda df: df.apply(
                lambda row: bool(re.search(rf"(?i)\b{row.word}\b", row.content)), axis=1
            )
        )
        .query("match")
        .groupby("post_id")
        .apply(lambda x: ",".join(map(str, sorted(set(x.topic_id)))))
        .reset_index(name="topic")
        .merge(posts[["post_id"]], how="right")
        .fillna("Ambiguous!")
    )
