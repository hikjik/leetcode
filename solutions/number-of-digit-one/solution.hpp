#pragma once

#include <cstring>
#include <string>

/*
  233. Number of Digit One
  https://leetcode.com/problems/number-of-digit-one/
  Difficulty: Hard
  Tags: Math, Dynamic Programming, Recursion
  Time:
  Space:
*/

class Solution {
private:
  inline static int DP[10][10][2];

public:
  static int countDigitOne(int n) {
    std::memset(DP, -1, sizeof(DP));
    return countDigitOne(std::to_string(n), 0, 0, 1);
  }

private:
  static int countDigitOne(const std::string &number, size_t position,
                           size_t ones_before, size_t tight) {
    if (position == number.size()) {
      return ones_before;
    }

    int &total = DP[position][ones_before][tight];
    if (total != -1) {
      return total;
    }
    total = 0;

    size_t upper = tight ? number[position] - '0' : 9;
    for (size_t digit = 0; digit <= upper; ++digit) {
      total += countDigitOne(number, position + 1, (digit == 1) + ones_before,
                             tight && digit == upper);
    }
    return total;
  }
};
