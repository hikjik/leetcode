#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string removeTrailingZeros(std::string num) {
    return num.substr(0, num.find_last_not_of('0') + 1);
  }
};
