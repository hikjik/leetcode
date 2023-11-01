#pragma once

#include <algorithm>
#include <vector>

/*
  121. Best Time to Buy and Sell Stock
  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
  Difficulty: Easy
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int maxProfit(const std::vector<int> &prices) {
    int max_profit = 0;
    int profit_after = 0;
    for (auto it = prices.rbegin(); it != prices.rend(); ++it) {
      max_profit = std::max(max_profit, profit_after - *it);
      profit_after = std::max(profit_after, *it);
    }
    return max_profit;
  }
};
