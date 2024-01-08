#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int countLetters(std::string s) {
    int ans = 1, cnt = 1;
    for (int i = 1; i < std::ssize(s); ++i) {
      if (s[i] != s[i - 1]) {
        cnt = 0;
      }
      ans += ++cnt;
    }
    return ans;
  }
};
