import pandas as pd


def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.assign(bonus=employees.salary * 2)
