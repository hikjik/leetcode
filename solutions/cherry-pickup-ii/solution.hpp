#pragma once

#include <algorithm>
#include <cstring>
#include <vector>

class Solution {
private:
  static const int kMaxRow = 70;
  static const int kMaxCol = 70;
  static inline int dp[kMaxCol + 1][kMaxCol + 1][kMaxRow + 1];

  static int dfs(int c1, int c2, int r,
                 const std::vector<std::vector<int>> &grid) {
    const int m = grid.size(), n = grid.back().size();

    if (c1 < 0 || c1 == n || c2 < 0 || c2 == n || r == m) {
      return 0;
    }

    auto &cnt = dp[c1][c2][r];
    if (cnt != -1) {
      return cnt;
    }

    cnt = 0;
    const auto cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
    for (int i1 = -1; i1 < 2; ++i1) {
      for (int i2 = -1; i2 < 2; ++i2) {
        cnt = std::max(cnt, cherries + dfs(c1 + i1, c2 + i2, r + 1, grid));
      }
    }
    return cnt;
  }

public:
  static int cherryPickup(const std::vector<std::vector<int>> &grid) {
    std::memset(dp, -1, sizeof(dp));
    return dfs(0, grid.back().size() - 1, 0, grid);
  }
};
