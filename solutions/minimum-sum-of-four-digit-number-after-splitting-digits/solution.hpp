#pragma once

#include <algorithm>
#include <string>

/*
  2160. Minimum Sum of Four Digit Number After Splitting Digits
  https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
  Difficulty: Easy
  Tags: Math, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int minimumSum(int num) {
    auto s = std::to_string(num);
    std::sort(s.begin(), s.end());
    const auto new1 = (s[0] - '0') * 10 + s[2] - '0';
    const auto new2 = (s[1] - '0') * 10 + s[3] - '0';
    return new1 + new2;
  }
};
