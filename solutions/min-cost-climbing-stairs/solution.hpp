#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int minCostClimbingStairs(const std::vector<int> &cost) {
    int a = cost[0], b = cost[1];
    for (size_t i = 2; i < cost.size(); ++i) {
      const int c = std::min(a, b) + cost[i];
      a = b, b = c;
    }
    return std::min(a, b);
  }
};
