#pragma once

#include <array>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minCost(const std::vector<std::vector<int>> &costs) {
    std::array<int, 3> dp{};
    for (const auto &cost : costs) {
      dp = {
          cost[0] + std::min(dp[1], dp[2]),
          cost[1] + std::min(dp[0], dp[2]),
          cost[2] + std::min(dp[0], dp[1]),
      };
    }
    return std::ranges::min(dp);
  }
};
