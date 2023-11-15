import pandas as pd


def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    salary = employee.salary.sort_values(ascending=False).drop_duplicates().iloc[1:2]
    return pd.DataFrame({"SecondHighestSalary": salary if salary.size else [None]})
