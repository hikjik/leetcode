#pragma once

#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
private:
  static const int kMaxSum = 5000;

public:
  static int tallestBillboard(const std::vector<int> &rods) {
    // dp[taller - shorter] = taller
    std::vector<int> dp(kMaxSum + 1, -1);
    dp[0] = 0;

    for (auto r : rods) {
      auto new_dp = dp;

      for (int d = 0; d <= kMaxSum; ++d) {
        if (dp[d] < 0) {
          continue;
        }

        // Add r to the taller stand
        new_dp[d + r] = std::max(new_dp[d + r], dp[d]);

        // Add r to the shorter stand
        const auto new_diff = std::abs(d - r);
        new_dp[new_diff] = std::max(new_dp[new_diff], dp[d] + std::min(d, r));
      }
      dp.swap(new_dp);
    }

    return dp[0];
  }
};
