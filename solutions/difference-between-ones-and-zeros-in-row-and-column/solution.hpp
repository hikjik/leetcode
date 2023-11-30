#pragma once

#include <vector>

// Time: O(NM)
// Space: O(N+M)

class Solution {
public:
  static std::vector<std::vector<int>>
  onesMinusZeros(const std::vector<std::vector<int>> &grid) {
    const int m = grid.size(), n = grid.back().size();

    std::vector<int> rows(m), cols(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        rows[i] += grid[i][j];
        cols[j] += grid[i][j];
      }
    }

    std::vector ans(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i][j] = 2 * rows[i] - m + 2 * cols[j] - n;
      }
    }
    return ans;
  }
};
