#pragma once

#include <string>

class Solution {
public:
  static int minOperations(std::string s) {
    const int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += s[i] - '0' == (i & 1);
    }
    return std::min(cnt, n - cnt);
  }
};
