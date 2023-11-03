#pragma once

#include <vector>

// Time:
// Space:

class NumMatrix {
public:
  NumMatrix(const std::vector<std::vector<int>> &mat)
      : dp(mat.size() + 1, std::vector<int>(mat.back().size() + 1)) {
    for (size_t i = 0; i < dp.size() - 1; ++i) {
      for (size_t j = 0; j < dp.back().size() - 1; ++j) {
        dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + mat[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return dp[row2 + 1][col2 + 1] + dp[row1][col1] - dp[row2 + 1][col1] -
           dp[row1][col2 + 1];
  }

private:
  std::vector<std::vector<int>> dp;
};
