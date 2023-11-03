#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int titleToNumber(std::string columnTitle) {
    int number = 0;
    for (auto c : columnTitle) {
      number = number * 26 + (c - 'A' + 1);
    }
    return number;
  }
};
