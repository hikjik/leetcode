#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int paintWalls(const std::vector<int> &cost,
                        const std::vector<int> &time) {
    const int n = cost.size();

    std::vector<int> dp(n + 1, 0x3f3f3f3f);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
      for (int r = n; r > 0; --r) {
        dp[r] = std::min(dp[r], cost[i] + dp[std::max(0, r - time[i] - 1)]);
      }
    }

    return dp[n];
  }
};
