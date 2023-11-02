#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int ways(const std::vector<std::string> &pizza, int k) {
    apples.clear(), dp.clear();
    int m = pizza.size(), n = pizza.back().size();

    apples.resize(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        apples[i][j] = (pizza[i - 1][j - 1] == 'A') + apples[i - 1][j] +
                       apples[i][j - 1] - apples[i - 1][j - 1];
      }
    }

    dp.resize(m, std::vector<std::vector<int>>(n, std::vector<int>(k, -1)));
    return ways(0, 0, k - 1, m, n);
  }

private:
  static inline std::vector<std::vector<std::vector<int>>> dp;
  static inline std::vector<std::vector<int>> apples;
  static inline const int mod = 1e9 + 7;

  static int ways(int r, int c, int k, int m, int n) {
    if (k == 0) {
      return 1;
    }
    if (dp[r][c][k] != -1) {
      return dp[r][c][k];
    }

    dp[r][c][k] = 0;
    for (int i = r + 1; i < m; ++i) {
      if (hasApple(r, i - 1, c, n - 1) && hasApple(i, m - 1, c, n - 1)) {
        dp[r][c][k] += ways(i, c, k - 1, m, n);
        dp[r][c][k] %= mod;
      }
    }

    for (int j = c + 1; j < n; ++j) {
      if (hasApple(r, m - 1, c, j - 1) && hasApple(r, m - 1, j, n - 1)) {
        dp[r][c][k] += ways(r, j, k - 1, m, n);
        dp[r][c][k] %= mod;
      }
    }

    return dp[r][c][k];
  }

  static bool hasApple(int r1, int r2, int c1, int c2) {
    const auto apples_count = apples[r2 + 1][c2 + 1] - apples[r2 + 1][c1] -
                              apples[r1][c2 + 1] + apples[r1][c1];
    return apples_count > 0;
  }
};
