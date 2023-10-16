#pragma once

#include <string>

class Solution {
public:
  static int divisorSubstrings(int num, int k) {
    int cnt = 0;
    const auto s = std::to_string(num);
    for (size_t i = 0; i + k - 1 < s.size(); ++i) {
      const auto d = std::stoi(s.substr(i, k));
      if (d && num % d == 0) {
        ++cnt;
      }
    }
    return cnt;
  }
};
