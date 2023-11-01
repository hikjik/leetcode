#pragma once

#pragma once

#include <vector>

/*
  123. Best Time to Buy and Sell Stock III
  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
  Difficulty: Hard
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int maxProfit(const std::vector<int> &prices) {
    int k = 2;
    std::vector dp(2 * k + 1, std::vector<int>(prices.size(), -1));
    return maxProfit(0, 2 * k, false, prices, &dp);
  }

private:
  static int maxProfit(size_t i, int k, bool buy,
                       const std::vector<int> &prices,
                       std::vector<std::vector<int>> *dp) {
    if (k == 0 || i == prices.size()) {
      return 0;
    }

    auto &profit = (*dp)[k][i];
    if (profit != -1) {
      return profit;
    }

    profit =
        (buy ? 1 : -1) * prices[i] + maxProfit(i + 1, k - 1, !buy, prices, dp);
    profit = std::max(profit, maxProfit(i + 1, k, buy, prices, dp));
    return profit;
  }
};
