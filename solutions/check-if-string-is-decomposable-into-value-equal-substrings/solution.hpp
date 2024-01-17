#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool isDecomposable(std::string s) {
    int len = 1, cnt = 0;
    for (int i = 1; i <= std::ssize(s); ++i) {
      if (i == std::ssize(s) || s[i] != s[i - 1]) {
        if (len % 3 == 2 && cnt++ || len % 3 == 1) {
          return false;
        }
        len = 0;
      }
      ++len;
    }
    return cnt == 1;
  }
};
