#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool makePalindrome(std::string s) {
    const int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n / 2; ++i) {
      cnt += s[i] != s[n - i - 1];
    }
    return cnt <= 2;
  }
};
