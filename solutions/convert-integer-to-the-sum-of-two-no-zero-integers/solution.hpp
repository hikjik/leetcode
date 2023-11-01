#pragma once

#include <string>
#include <vector>

/*
  1317. Convert Integer to the Sum of Two No-Zero Integers
  https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i < n; ++i) {
      if (std::to_string(i).find('0') == std::string::npos &&
          std::to_string(n - i).find('0') == std::string::npos) {
        return {i, n - i};
      }
    }

    throw;
  }
};
