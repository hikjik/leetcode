#pragma once

#include <vector>

/*
  714. Best Time to Buy and Sell Stock with Transaction Fee
  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
  Difficulty: Medium
  Tags: Array, Dynamic Programming, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int maxProfit(const std::vector<int> &prices, int fee) {
    const auto n = prices.size();

    std::vector<std::vector<int>> dp(2, std::vector<int>(n, 0));
    dp[1][0] = -prices[0];

    for (size_t i = 1; i < n; ++i) {
      dp[0][i] = std::max(dp[0][i - 1], dp[1][i - 1] + prices[i] - fee);
      dp[1][i] = std::max(dp[1][i - 1], dp[0][i - 1] - prices[i]);
    }

    return dp[0][n - 1];
  }
};
