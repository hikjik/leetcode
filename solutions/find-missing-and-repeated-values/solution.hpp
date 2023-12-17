#pragma once

#include <vector>

// Time: O(N^2)
// Space: O(N^2)

class Solution {
public:
  static std::vector<int>
  findMissingAndRepeatedValues(const std::vector<std::vector<int>> &grid) {
    const int n = grid.size();
    std::vector<int> cnt(n * n + 1);
    for (const auto &row : grid) {
      for (auto a : row) {
        ++cnt[a];
      }
    }

    std::vector<int> ans(2);
    for (int i = 1; i <= n * n; ++i) {
      if (!cnt[i]) {
        ans[1] = i;
      } else if (cnt[i] == 2) {
        ans[0] = i;
      }
    }
    return ans;
  }
};
