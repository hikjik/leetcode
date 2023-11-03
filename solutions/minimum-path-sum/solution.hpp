#pragma once

#include <climits>
#include <vector>

// Time: O(NM)
// Space: O(1)

namespace memo {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int minPathSum(const std::vector<std::vector<int>> &grid) {
    const int m = grid.size(), n = grid.back().size();
    std::vector memo(m, std::vector<int>(n, -1));
    return minPathSum(m - 1, n - 1, grid, &memo);
  }

private:
  static int minPathSum(int i, int j, const std::vector<std::vector<int>> &grid,
                        std::vector<std::vector<int>> *memo) {
    if (i < 0 || j < 0) {
      return INT_MAX;
    }
    if (i == 0 && j == 0) {
      return grid[i][j];
    }

    auto &cost = (*memo)[i][j];
    if (cost == -1) {
      cost = grid[i][j] + std::min(minPathSum(i - 1, j, grid, memo),
                                   minPathSum(i, j - 1, grid, memo));
    }
    return cost;
  }
};

} // namespace memo

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int minPathSum(const std::vector<std::vector<int>> &grid) {
    const int m = grid.size(), n = grid.back().size();

    std::vector dp(m, std::vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < n; ++j) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};

} // namespace dp

namespace inplace {

// Time: O(NM)
// Space: O(1)
class Solution {
public:
  static int minPathSum(std::vector<std::vector<int>> &grid) {
    const int m = grid.size(), n = grid.back().size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i || j) {
          grid[i][j] += std::min(i ? grid[i - 1][j] : INT_MAX,
                                 j ? grid[i][j - 1] : INT_MAX);
        }
      }
    }
    return grid[m - 1][n - 1];
  }
};

} // namespace inplace
