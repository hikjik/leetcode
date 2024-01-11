import pandas as pd


def leetflex_banned_accnts(log_info: pd.DataFrame) -> pd.DataFrame:
    return (
        log_info.merge(log_info, on="account_id")
        .query("login_x <= logout_y and login_y <= logout_x")
        .query("ip_address_x != ip_address_y")[["account_id"]]
        .drop_duplicates()
    )
