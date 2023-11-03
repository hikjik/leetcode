#pragma once

#include <vector>

// Time:
// Space:

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
