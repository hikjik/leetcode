#pragma once

#include <string>

class Solution {
public:
  static std::string removeStars(std::string s) {
    int n = 0;
    for (auto c : s) {
      if (c == '*') {
        n--;
      } else {
        s[n++] = c;
      }
    }
    return s.substr(0, n);
  }
};
