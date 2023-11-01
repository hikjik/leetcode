#pragma once

#include <string>
#include <vector>

/*
  2496. Maximum Value of a String in an Array
  https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static int maximumValue(const std::vector<std::string> &strs) {
    int max_value = 0;
    for (const auto &str : strs) {
      max_value = std::max(max_value, computeValue(str));
    }
    return max_value;
  }

private:
  static int computeValue(const std::string &str) {
    int value = 0;
    for (auto c : str) {
      if (std::isdigit(c)) {
        value = value * 10 + c - '0';
      } else {
        return str.size();
      }
    }
    return value;
  }
};
