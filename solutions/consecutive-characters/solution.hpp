#pragma once

#include <string>

class Solution {
public:
  static int maxPower(std::string s) {
    int ans = 0;
    for (int i = 1, cnt = 1; i <= std::ssize(s); ++i, ++cnt) {
      if (i == std::ssize(s) || s[i] != s[i - 1]) {
        ans = std::max(ans, cnt);
        cnt = 0;
      }
    }
    return ans;
  }
};
