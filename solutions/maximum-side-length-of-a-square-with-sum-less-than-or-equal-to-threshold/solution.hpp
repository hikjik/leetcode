#pragma once

#include <vector>

class Solution {
public:
  static int maxSideLength(const std::vector<std::vector<int>> &mat,
                           int threshold) {
    int m = mat.size(), n = mat.back().size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        dp[i][j] =
            dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }

    auto subMatrixSum = [&dp](int r1, int r2, int c1, int c2) -> int {
      return dp[r2 + 1][c2 + 1] + dp[r1][c1] - dp[r2 + 1][c1] - dp[r1][c2 + 1];
    };

    int max_side = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int side = max_side; side < std::min(m - i, n - j); ++side) {
          if (subMatrixSum(i, i + side, j, j + side) > threshold) {
            break;
          }
          max_side = std::max(max_side, side + 1);
        }
      }
    }
    return max_side;
  }
};
