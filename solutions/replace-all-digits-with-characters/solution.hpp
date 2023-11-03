#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string replaceDigits(std::string s) {
    for (int i = 1; i < std::ssize(s); i += 2) {
      s[i] = s[i - 1] + s[i] - '0';
    }
    return s;
  }
};
