import pandas as pd


def find_subtasks(tasks: pd.DataFrame, executed: pd.DataFrame) -> pd.DataFrame:
    return pd.concat(
        [
            tasks.assign(
                subtask_id=tasks.subtasks_count.apply(lambda x: range(1, x + 1))
            )
            .drop(columns="subtasks_count")
            .explode("subtask_id"),
            executed,
        ]
    ).drop_duplicates(keep=False)
