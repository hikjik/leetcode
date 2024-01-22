import pandas as pd


def get_election_results(votes: pd.DataFrame) -> pd.DataFrame:
    return (
        votes.query("not candidate.isnull()")
        .assign(
            vote=lambda x: x.groupby("voter").candidate.transform(
                lambda x: 1 / x.count()
            ),
            votes_count=lambda x: x.groupby("candidate").vote.transform("sum"),
        )
        .query("votes_count == votes_count.max()")[["candidate"]]
        .drop_duplicates()
        .sort_values("candidate")
    )
