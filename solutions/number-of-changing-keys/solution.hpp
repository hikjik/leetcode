#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int countKeyChanges(std::string s) {
    int ans = 0;
    for (int i = 1; i < std::ssize(s); ++i) {
      ans += std::tolower(s[i]) != std::tolower(s[i - 1]);
    }
    return ans;
  }
};
