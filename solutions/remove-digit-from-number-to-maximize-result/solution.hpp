#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string removeDigit(std::string number, char digit) {
    for (size_t i = 0; i + 1 < number.size(); ++i) {
      if (number[i] == digit && number[i] < number[i + 1]) {
        return number.erase(i, 1);
      }
    }
    return number.erase(number.rfind(digit), 1);
  }
};
