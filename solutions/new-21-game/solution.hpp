#pragma once

#include <vector>

class Solution {
public:
  static double new21Game(int n, int k, int maxPts) {
    if (k == 0 || n >= k - 1 + maxPts) {
      return 1.0;
    }

    std::vector<double> dp(n + 1);
    dp[0] = 1.0;

    double sum = dp[0], ans = 0.0;
    for (int i = 1; i <= n; ++i) {
      dp[i] = sum / maxPts;
      i < k ? sum += dp[i] : ans += dp[i];
      if (i - maxPts >= 0) {
        sum -= dp[i - maxPts];
      }
    }
    return ans;
  }
};
