#pragma once

#include <algorithm>
#include <string>

/*
  2264. Largest 3-Same-Digit Number in String
  https://leetcode.com/problems/largest-3-same-digit-number-in-string/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string largestGoodInteger(std::string num) {
    std::string ans;
    for (size_t i = 0; i + 2 < num.size(); ++i) {
      if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
        ans = std::max(ans, num.substr(i, 3));
      }
    }
    return ans;
  }
};
