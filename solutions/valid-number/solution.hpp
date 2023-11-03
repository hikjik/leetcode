#pragma once

#include <regex>
#include <string>

// Time:
// Space:

class Solution {
public:
  static bool isNumber(std::string s) {
    static const std::regex regex(
        R"([-+]?(\d+|\d*\.\d+|\d+\.\d*)([eE][-+]?\d+)?)");
    return std::regex_match(s, regex);
  }
};
