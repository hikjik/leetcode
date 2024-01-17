import pandas as pd


def concatenate_info(person: pd.DataFrame) -> pd.DataFrame:
    return (
        person.sort_values("person_id", ascending=False)
        .assign(name=person.name + "(" + person.profession.str[:1] + ")")
        .drop(columns="profession")
    )
