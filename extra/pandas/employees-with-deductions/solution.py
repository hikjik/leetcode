import pandas as pd


def employees_with_deductions(
    employees: pd.DataFrame, logs: pd.DataFrame
) -> pd.DataFrame:
    return (
        employees.merge(logs, on="employee_id", how="left")
        .assign(
            working_time_m=lambda x: ((x.out_time - x.in_time).dt.seconds + 59) // 60
        )
        .fillna(0)
        .groupby(["employee_id", "needed_hours"])
        .working_time_m.sum()
        .reset_index(name="working_time_total_m")
        .query("working_time_total_m < 60 * needed_hours")[["employee_id"]]
        .drop_duplicates()
    )
