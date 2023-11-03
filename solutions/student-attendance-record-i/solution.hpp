#pragma once

#include <algorithm>
#include <string>

// Time:
// Space:

class Solution {
public:
  static bool checkRecord(std::string s) {
    if (std::count(s.begin(), s.end(), 'A') > 1) {
      return false;
    }
    for (size_t i = 0; i + 2 < s.size(); ++i) {
      if (s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L') {
        return false;
      }
    }
    return true;
  }
};
