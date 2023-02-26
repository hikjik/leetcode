#pragma once

#include <vector>

class Solution {
public:
  static int maxProfit(std::vector<int> &prices, int fee) {
    size_t n = prices.size();

    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
    dp[0][1] = -prices[0];

    for (size_t i = 1; i < prices.size(); ++i) {
      dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
      dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[n - 1][0];
  }
};
