#pragma once

#include <regex>
#include <string>

/*
  65. Valid Number
  https://leetcode.com/problems/valid-number/
  Difficulty: Hard
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static bool isNumber(std::string s) {
    static const std::regex regex(
        R"([-+]?(\d+|\d*\.\d+|\d+\.\d*)([eE][-+]?\d+)?)");
    return std::regex_match(s, regex);
  }
};
