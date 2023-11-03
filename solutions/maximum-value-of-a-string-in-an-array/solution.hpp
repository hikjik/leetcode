#pragma once

#include <string>
#include <vector>

// Time:
// Space:

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
