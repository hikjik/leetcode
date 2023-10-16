#pragma once

#include <vector>

class Solution {
public:
  static int minMaxGame(const std::vector<int> &nums) {
    std::vector<int> dp(nums);
    for (size_t k = 1; k < dp.size(); k <<= 1) {
      for (size_t i = 0; i < dp.size() / 2; ++i) {
        dp[i] = i % 2 == 0 ? std::min(dp[2 * i], dp[2 * i + 1])
                           : std::max(dp[2 * i], dp[2 * i + 1]);
      }
    }
    return dp[0];
  }
};
