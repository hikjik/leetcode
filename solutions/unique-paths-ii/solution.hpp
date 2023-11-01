#pragma once

#include <vector>

/*
  63. Unique Paths II
  https://leetcode.com/problems/unique-paths-ii/
  Difficulty: Medium
  Tags: Array, Dynamic Programming, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static int
  uniquePathsWithObstacles(const std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid.back().size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
    dp[0][0] = 1 - grid[0][0];

    for (int i = 1; i < m; ++i) {
      dp[i][0] = dp[i - 1][0];
      dp[i][0] *= 1 - grid[i][0];
    }
    for (int j = 1; j < n; ++j) {
      dp[0][j] = dp[0][j - 1];
      dp[0][j] *= 1 - grid[0][j];
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        dp[i][j] *= 1 - grid[i][j];
      }
    }
    return dp[m - 1][n - 1];
  }
};
