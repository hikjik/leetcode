#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minimumLength(std::string s) {
    int l = 0, r = s.size() - 1;
    while (l < r && s[l] == s[r]) {
      const auto c = s[l];
      while (l <= r && s[l] == c) {
        ++l;
      }
      while (l <= r && s[r] == c) {
        --r;
      }
    }
    return r - l + 1;
  }
};
