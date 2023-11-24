import pandas as pd


def movie_rating(
    movies: pd.DataFrame, users: pd.DataFrame, movie_rating: pd.DataFrame
) -> pd.DataFrame:
    user_name = (
        users.merge(movie_rating, on="user_id")
        .groupby("name")
        .movie_id.count()
        .sort_values(ascending=False)
        .head(1)
        .reset_index()["name"][0]
    )
    movie_name = (
        movie_rating[movie_rating.created_at.between("2020-02-01", "2020-02-29")]
        .merge(movies, on="movie_id")
        .groupby("title")
        .rating.mean()
        .sort_values(ascending=False)
        .head(1)
        .reset_index()["title"][0]
    )
    return pd.DataFrame({"results": [user_name, movie_name]})
