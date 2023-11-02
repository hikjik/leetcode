#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string modifyString(std::string s) {
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == '?') {
        for (auto c = 'a'; c <= 'c'; ++c) {
          if ((i == 0 || s[i - 1] != c) &&
              (i + 1 == s.size() || s[i + 1] != c)) {
            s[i] = c;
            break;
          }
        }
      }
    }
    return s;
  }
};
