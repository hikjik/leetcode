#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static bool PredictTheWinner(const std::vector<int> &nums) {
    const int n = nums.size();
    std::vector dp(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = nums[i];
    }

    for (int d = 1; d < n; ++d) {
      for (int l = 0; l < n - d; ++l) {
        const auto r = l + d;
        dp[l][r] = std::max(nums[l] - dp[l + 1][r], nums[r] - dp[l][r - 1]);
      }
    }

    return dp[0][n - 1] >= 0;
  }
};