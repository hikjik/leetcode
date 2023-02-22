#pragma once

#include <numeric>
#include <vector>

class Solution {
public:
  static int maximumWealth(const std::vector<std::vector<int>> &accounts) {
    int maximum_wealth = 0;
    for (const auto &account : accounts) {
      int wealth = std::accumulate(account.begin(), account.end(), 0);
      maximum_wealth = std::max(maximum_wealth, wealth);
    }
    return maximum_wealth;
  }
};
