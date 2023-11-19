#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static long long minimumSteps(std::string s) {
    long long ans = 0;
    for (int i = 0, j = 0; j < std::ssize(s); ++j) {
      if (s[j] == '0') {
        ans += j - i;
        ++i;
      }
    }
    return ans;
  }
};
