import pandas as pd


def friendly_movies(tv_program: pd.DataFrame, content: pd.DataFrame) -> pd.DataFrame:
    return (
        tv_program.merge(
            content.assign(content_id=content.content_id.astype("int")),
            on="content_id",
            how="left",
        )
        .query("program_date.dt.year == 2020 and program_date.dt.month == 6")
        .query("Kids_content == 'Y' and content_type == 'Movies'")[["title"]]
        .drop_duplicates()
    )
