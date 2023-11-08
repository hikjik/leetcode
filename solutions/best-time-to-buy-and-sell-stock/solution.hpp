#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int maxProfit(const std::vector<int> &prices) {
    int profit = 0;
    for (int min_price = prices.front(); auto price : prices) {
      profit = std::max(profit, price - min_price);
      min_price = std::min(min_price, price);
    }
    return profit;
  }
};
