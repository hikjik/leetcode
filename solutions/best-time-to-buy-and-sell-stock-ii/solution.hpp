#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int maxProfit(const std::vector<int> &prices) {
    int profit = 0;
    for (int i = 1; i < std::ssize(prices); ++i) {
      if (prices[i] > prices[i - 1]) {
        profit += prices[i] - prices[i - 1];
      }
    }
    return profit;
  }
};
