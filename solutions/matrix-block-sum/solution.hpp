#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>>
  matrixBlockSum(const std::vector<std::vector<int>> &mat, int k) {
    int m = mat.size(), n = mat.back().size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + mat[i][j];
      }
    }

    std::vector<std::vector<int>> sum(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int r1 = std::max(i - k, 0), c1 = std::max(j - k, 0);
        int r2 = std::min(i + k, m - 1), c2 = std::min(j + k, n - 1);
        sum[i][j] =
            dp[r2 + 1][c2 + 1] + dp[r1][c1] - dp[r2 + 1][c1] - dp[r1][c2 + 1];
      }
    }
    return sum;
  }
};
