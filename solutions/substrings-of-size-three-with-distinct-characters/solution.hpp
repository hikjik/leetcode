#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int countGoodSubstrings(std::string s) {
    int cnt = 0;
    for (int i = 0; i + 2 < std::ssize(s); ++i) {
      if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
        ++cnt;
      }
    }
    return cnt;
  }
};
