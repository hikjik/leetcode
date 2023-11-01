#pragma once

#include <string>
#include <vector>

/*
  2283. Check if Number Has Equal Digit Count and Digit Value
  https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/
  Difficulty: Easy
  Tags: Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static bool digitCount(std::string num) {
    std::vector<int> counter(10);
    for (auto c : num) {
      ++counter[c - '0'];
    }

    for (size_t i = 0; i < num.size(); ++i) {
      if (num[i] - '0' != counter[i]) {
        return false;
      }
    }
    return true;
  }
};
