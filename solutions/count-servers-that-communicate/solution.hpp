#pragma once

#include <vector>

// Time: O(NM)
// Space: O(N+M)

class Solution {
public:
  static int countServers(const std::vector<std::vector<int>> &grid) {
    const int m = grid.size(), n = grid.back().size();

    std::vector<int> rows(m), cols(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          ++rows[i], ++cols[j];
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] && (rows[i] > 1 || cols[j] > 1)) {
          ++ans;
        }
      }
    }
    return ans;
  }
};
