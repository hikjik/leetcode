import pandas as pd


def salaries_difference(salaries: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame(
        {
            "salary_difference": [
                abs(
                    salaries.query("department == 'Marketing'").salary.max()
                    - salaries.query("department == 'Engineering'").salary.max()
                )
            ]
        }
    )
