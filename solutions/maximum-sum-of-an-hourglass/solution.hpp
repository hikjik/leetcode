#pragma once

#include <vector>

// Time: O(NM)
// Space: O(1)

class Solution {
public:
  static int maxSum(const std::vector<std::vector<int>> &grid) {
    const int m = grid.size(), n = grid.back().size();
    int ans = 0;
    for (int i = 0; i + 2 < m; ++i) {
      for (int j = 0; j + 2 < n; ++j) {
        const int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] +
                        grid[i + 1][j + 1] + grid[i + 2][j] +
                        grid[i + 2][j + 1] + grid[i + 2][j + 2];
        ans = std::max(ans, sum);
      }
    }
    return ans;
  }
};
