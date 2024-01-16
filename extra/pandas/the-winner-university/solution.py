import pandas as pd


def find_winner(new_york: pd.DataFrame, california: pd.DataFrame) -> pd.DataFrame:
    ny_score = new_york.query("score >= 90").student_id.count()
    ca_score = california.query("score >= 90").student_id.count()

    if ny_score > ca_score:
        winner = "New York University"
    elif ny_score < ca_score:
        winner = "California University"
    else:
        winner = "No Winner"

    return pd.DataFrame({"winner": [winner]})
