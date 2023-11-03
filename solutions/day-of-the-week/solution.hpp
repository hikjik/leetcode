#pragma once

#include <array>
#include <chrono>
#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string dayOfTheWeek(int day, int month, int year) {
    static const std::array<std::string, 7> weekdays{
        "Sunday",   "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"};

    std::chrono::year_month_day ymd{std::chrono::year{year} / month / day};
    std::chrono::weekday weekday{std::chrono::sys_days(ymd)};
    return weekdays[weekday.c_encoding()];
  }
};
