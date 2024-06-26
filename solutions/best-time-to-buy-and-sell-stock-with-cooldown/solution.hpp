#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxProfit(const std::vector<int> &prices) {
    size_t n = prices.size();

    std::vector<std::vector<int>> dp(2, std::vector<int>(n, 0));
    dp[1][0] = -prices[0];

    for (size_t i = 1; i < n; ++i) {
      dp[0][i] = std::max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
      dp[1][i] = std::max(dp[1][i - 1], (i > 1 ? dp[0][i - 2] : 0) - prices[i]);
    }

    return dp[0][n - 1];
  }
};
