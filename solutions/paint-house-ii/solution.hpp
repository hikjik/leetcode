#pragma once

#include <climits>
#include <ranges>
#include <vector>

// Time: O(NK)
// Space: O(1)

class Solution {
public:
  static int minCostII(const std::vector<std::vector<int>> &costs) {
    int pmin1 = 0, pmin2 = 0;
    int pindex = -1;

    for (int i = 0; i < std::ssize(costs); ++i) {
      int min1 = INT_MAX, min2 = INT_MAX;
      int index = -1;
      for (int j = 0; j < std::ssize(costs[i]); ++j) {
        const auto cost = costs[i][j] + (j == pindex ? pmin2 : pmin1);
        if (cost < min1) {
          min2 = std::exchange(min1, cost);
          index = j;
        } else if (cost < min2) {
          min2 = cost;
        }
      }
      pmin1 = min1, pmin2 = min2;
      pindex = index;
    }
    return pmin1;
  }
};
