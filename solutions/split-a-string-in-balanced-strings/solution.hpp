#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int balancedStringSplit(std::string s) {
    int ans = 0, cnt = 0;
    for (auto c : s) {
      cnt += c == 'R' ? 1 : -1;
      ans += !cnt;
    }
    return ans;
  }
};
