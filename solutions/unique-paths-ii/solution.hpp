#pragma once

#include <vector>

// Time: O(NM)
// Space: O(N)

namespace memo {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int
  uniquePathsWithObstacles(const std::vector<std::vector<int>> &obstacleGrid) {
    const int m = obstacleGrid.size(), n = obstacleGrid.back().size();
    std::vector memo(m, std::vector<int>(n, -1));
    memo[0][0] = 1;
    return uniquePathsWithObstacles(m - 1, n - 1, obstacleGrid, &memo);
  }

private:
  static int
  uniquePathsWithObstacles(int i, int j,
                           const std::vector<std::vector<int>> &obstacleGrid,
                           std::vector<std::vector<int>> *memo) {
    if (i < 0 || j < 0 || obstacleGrid[i][j]) {
      return 0;
    }
    auto &cnt = (*memo)[i][j];
    if (cnt == -1) {
      cnt = uniquePathsWithObstacles(i - 1, j, obstacleGrid, memo) +
            uniquePathsWithObstacles(i, j - 1, obstacleGrid, memo);
    }
    return cnt;
  }
};

} // namespace memo

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int
  uniquePathsWithObstacles(const std::vector<std::vector<int>> &obstacleGrid) {
    const int m = obstacleGrid.size(), n = obstacleGrid.back().size();
    std::vector dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j)
        if (!obstacleGrid[i][j]) {
          dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
        }
    }
    return dp[m][n];
  }
};

} // namespace dp

namespace optimized {

// Time: O(NM)
// Space: O(N)
class Solution {
public:
  static int
  uniquePathsWithObstacles(const std::vector<std::vector<int>> &obstacleGrid) {
    const int m = obstacleGrid.size(), n = obstacleGrid.back().size();
    std::vector<int> dp(n);
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (obstacleGrid[i][j]) {
          dp[j] = 0;
        } else {
          dp[j] += j ? dp[j - 1] : 0;
        }
      }
    }
    return dp.back();
  }
};

} // namespace optimized
