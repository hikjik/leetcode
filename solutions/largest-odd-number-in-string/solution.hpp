#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string largestOddNumber(std::string num) {
    for (int i = num.size() - 1; i >= 0; --i) {
      if ((num[i] - '0') & 1) {
        return num.substr(0, i + 1);
      }
    }
    return "";
  }
};
