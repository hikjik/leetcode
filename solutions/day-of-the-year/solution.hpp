#pragma once

#include <array>
#include <sstream>
#include <string>

class Solution {
public:
  static int dayOfYear(std::string date) {
    static const std::array<int, 12> days{31, 28, 31, 30, 31, 30,
                                          31, 31, 30, 31, 30, 31};

    std::stringstream stream(date);
    int year, month, day;
    char c;
    stream >> year >> c >> month >> c >> day;

    return day + std::accumulate(days.begin(), days.begin() + month - 1, 0) +
           (month > 2 && isLeapYear(year));
  }

  static bool isLeapYear(int year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
  }
};
