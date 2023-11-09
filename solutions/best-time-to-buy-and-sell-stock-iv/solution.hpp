#pragma once

#include <climits>
#include <vector>

// Time: O(NK)
// Space: O(K)

class Solution {
public:
  static int maxProfit(int k, const std::vector<int> &prices) {
    if (k >= std::ssize(prices) / 2) {
      return maxProfit(prices);
    }

    std::vector<int> buy(k + 1, INT_MIN);
    std::vector<int> sell(k + 1);
    for (auto price : prices) {
      for (int i = 1; i <= k; ++i) {
        buy[i] = std::max(buy[i], sell[i - 1] - price);
        sell[i] = std::max(sell[i], buy[i] + price);
      }
    }
    return sell.back();
  }

private:
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
