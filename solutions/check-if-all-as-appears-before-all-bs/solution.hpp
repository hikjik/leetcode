#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static bool checkString(std::string s) {
    for (size_t i = 0; i + 1 < s.size(); ++i) {
      if (s[i] == 'b' && s[i + 1] == 'a') {
        return false;
      }
    }
    return true;
  }
};
