#pragma once

#include <string>
#include <vector>

// Time: O(NM)
// Space: O(1)

class Solution {
public:
  static std::string longestCommonPrefix(const std::vector<std::string> &strs) {
    const int n = strs.size(), m = strs[0].size();
    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        if (std::ssize(strs[i]) <= j || strs[i][j] != strs[0][j]) {
          return strs[0].substr(0, j);
        }
      }
    }
    return strs[0];
  }
};
