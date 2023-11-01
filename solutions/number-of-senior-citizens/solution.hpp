#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  2678. Number of Senior Citizens
  https://leetcode.com/problems/number-of-senior-citizens/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static int countSeniors(const std::vector<std::string> &details) {
    return std::count_if(details.begin(), details.end(), [](const auto &s) {
      return (s[11] - '0') * 10 + s[12] - '0' > 60;
    });
  }
};
