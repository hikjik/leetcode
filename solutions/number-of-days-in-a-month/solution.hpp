#pragma once

#include <array>

// Time: O(1)
// Space: O(1)

class Solution {
public:
  static int numberOfDays(int year, int month) {
    static const std::array<int, 12> days{31, 28, 31, 30, 31, 30,
                                          31, 31, 30, 31, 30, 31};
    return days[month - 1] + (month == 2 && isLeapYear(year));
  }

  static bool isLeapYear(int year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
  }
};
