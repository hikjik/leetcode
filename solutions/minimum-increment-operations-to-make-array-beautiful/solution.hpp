#pragma once

#include <array>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static long long minIncrementOperations(const std::vector<int> &nums, int k) {
    std::array<long long, 3> dp{};
    for (auto num : nums) {
      dp = {
          dp[1],
          dp[2],
          std::max(0, k - num) + std::min({dp[0], dp[1], dp[2]}),
      };
    }
    return std::ranges::min(dp);
  }
};
