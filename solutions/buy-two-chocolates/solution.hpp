#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int buyChoco(std::vector<int> prices, int money) {
    std::partial_sort(prices.begin(), prices.begin() + 2, prices.end());
    const auto cost = prices[0] + prices[1];
    return cost > money ? money : money - cost;
  }
};
