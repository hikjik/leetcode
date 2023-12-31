#pragma once

#include <array>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int maxSumDivThree(const std::vector<int> &nums) {
    std::array<std::array<int, 3>, 2> dp{};
    for (auto num : nums) {
      for (auto sum : dp[0]) {
        const auto r = (sum + num) % 3;
        dp[1][r] = std::max(dp[1][r], sum + num);
      }
      dp[0] = dp[1];
    }
    return dp[0][0];
  }
};
