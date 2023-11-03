#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minimumCost(std::vector<int> cost) {
    std::sort(cost.begin(), cost.end(), std::greater<>());
    int sum = std::accumulate(cost.begin(), cost.end(), 0);
    for (size_t i = 2; i < cost.size(); i += 3) {
      sum -= cost[i];
    }
    return sum;
  }
};
