import pandas as pd


def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    salary = employee.salary.sort_values(ascending=False).drop_duplicates()
    salary = salary.iloc[N - 1 : N] if salary.size >= N else [None]
    return pd.DataFrame({f"getNthHighestSalary({N})": salary})
