#pragma once

#include <vector>

/*
  122. Best Time to Buy and Sell Stock II
  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
  Difficulty: Medium
  Tags: Array, Dynamic Programming, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int maxProfit(const std::vector<int> &prices) {
    int total_profit = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
      if (prices[i] > prices[i - 1]) {
        total_profit += prices[i] - prices[i - 1];
      }
    }
    return total_profit;
  }
};
