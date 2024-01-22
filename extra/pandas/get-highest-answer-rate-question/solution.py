import pandas as pd


def get_the_question(survey_log: pd.DataFrame) -> pd.DataFrame:
    return (
        survey_log.query("action != 'skip'")
        .groupby("question_id")
        .action.apply(lambda x: (x == "answer").mean())
        .reset_index(name="answer_rate")
        .query("answer_rate == answer_rate.max()")
        .query("question_id == question_id.min()")[["question_id"]]
        .rename(columns={"question_id": "survey_log"})
    )
