#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static bool checkOnesSegment(std::string s) {
    for (int i = 0; i + 1 < std::ssize(s); ++i) {
      if (s[i] == '0' && s[i + 1] == '1') {
        return false;
      }
    }
    return true;
  }
};
