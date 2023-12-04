#pragma once

#include <climits>
#include <vector>

// Time: O(N^3)
// Space: O(N^2)

namespace memo {

// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
  static int getMoneyAmount(int n) {
    std::vector memo(n + 1, std::vector<int>(n + 1, INT_MAX));
    return getMoneyAmount(1, n, &memo);
  }

private:
  static int getMoneyAmount(int i, int j, std::vector<std::vector<int>> *memo) {
    if (i >= j) {
      return 0;
    }
    auto &money = (*memo)[i][j];
    if (money == INT_MAX) {
      for (int l = i; l <= j; ++l) {
        money = std::min(money, l + std::max(getMoneyAmount(i, l - 1, memo),
                                             getMoneyAmount(l + 1, j, memo)));
      }
    }
    return money;
  }
};

} // namespace memo

namespace dp {

// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
  static int getMoneyAmount(int n) {
    std::vector dp(n + 1, std::vector<int>(n + 1));
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i + k <= n; ++i) {
        dp[i][i + k] = std::min(i + dp[i + 1][i + k], dp[i][i + k - 1] + i + k);
        for (int l = i + 1; l < i + k; ++l) {
          dp[i][i + k] = std::min(dp[i][i + k],
                                  l + std::max(dp[i][l - 1], dp[l + 1][i + k]));
        }
      }
    }
    return dp[1][n];
  }
};

} // namespace dp
