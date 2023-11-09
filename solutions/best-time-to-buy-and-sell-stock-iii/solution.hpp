#pragma once

#pragma once

#include <climits>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int maxProfit(const std::vector<int> &prices) {
    std::vector<int> buy(2, INT_MIN);
    std::vector<int> sell(2);
    for (auto price : prices) {
      buy[0] = std::max(buy[0], -price);
      sell[0] = std::max(sell[0], price + buy[0]);
      buy[1] = std::max(buy[1], sell[0] - price);
      sell[1] = std::max(sell[1], price + buy[1]);
    }
    return sell.back();
  }
};
