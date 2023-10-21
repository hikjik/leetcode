#pragma once

#include <algorithm>
#include <string>

class Solution {
public:
  static std::string reverseStr(std::string s, int k) {
    const int n = s.size();
    for (int i = 0; i < n; i += 2 * k) {
      std::reverse(s.begin() + i, s.begin() + std::min(i + k, n));
    }
    return s;
  }
};
