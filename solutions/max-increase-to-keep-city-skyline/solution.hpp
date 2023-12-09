#pragma once

#include <vector>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static int
  maxIncreaseKeepingSkyline(const std::vector<std::vector<int>> &grid) {
    const int n = grid.size();

    std::vector<int> maxCols(n), maxRows(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        maxRows[i] = std::max(maxRows[i], grid[i][j]);
        maxCols[j] = std::max(maxCols[j], grid[i][j]);
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans += std::min(maxRows[i], maxCols[j]) - grid[i][j];
      }
    }
    return ans;
  }
};
