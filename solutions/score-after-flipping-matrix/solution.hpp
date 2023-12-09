#pragma once

#include <vector>

// Time: O(NM)
// Space: O(1)

class Solution {
public:
  static int matrixScore(const std::vector<std::vector<int>> &grid) {
    const int m = grid.size(), n = grid.back().size();
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      int sum = 0;
      for (int i = 0; i < m; ++i) {
        sum += grid[i][0] ^ grid[i][j];
      }
      ans += std::max(sum, m - sum) * (1 << (n - j - 1));
    }
    return ans;
  }
};
