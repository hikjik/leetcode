#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static double knightProbability(int n, int steps, int row, int col) {
    static std::vector<std::pair<int, int>> dirs{
        {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};

    std::vector dp(n, std::vector<double>(n, 0.0));
    dp[row][col] = 1.0;

    for (int k = 0; k < steps; ++k) {
      std::vector new_dp(n, std::vector<double>(n));

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (!dp[i][j]) {
            continue;
          }

          for (const auto &[dr, dc] : dirs) {
            const int r = i + dr, c = j + dc;
            if (r >= 0 && r < n && c >= 0 && c < n) {
              new_dp[r][c] += dp[i][j] / 8;
            }
          }
        }
      }

      new_dp.swap(dp);
    }

    double prob = 0.0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        prob += dp[i][j];
      }
    }
    return prob;
  }
};
