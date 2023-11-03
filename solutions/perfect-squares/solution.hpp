#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int numSquares(int n) {
    std::vector<int> dp(n + 1, n);
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j * j <= i; j++) {
        dp[i] = std::min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};
