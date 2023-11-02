#pragma once

#include <array>
#include <cmath>
#include <numeric>
#include <sstream>
#include <string>

// Time:
// Space:

class Solution {
public:
  static int daysBetweenDates(std::string date1, std::string date2) {
    return std::abs(getDays(date1) - getDays(date2));
  }

private:
  static int getDays(const std::string &date) {
    static const std::array<int, 12> days{31, 28, 31, 30, 31, 30,
                                          31, 31, 30, 31, 30, 31};

    std::stringstream istream(date);
    int year, month, day;
    char c;
    istream >> year >> c >> month >> c >> day;

    int cnt = 0;
    for (int y = 1970; y < year; ++y) {
      cnt += isLeapYear(y) ? 366 : 365;
    }
    cnt += std::accumulate(days.begin(), days.begin() + month - 1, 0);
    cnt += month > 2 && isLeapYear(year);
    return cnt + day;
  }

  static bool isLeapYear(int year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
  }
};
