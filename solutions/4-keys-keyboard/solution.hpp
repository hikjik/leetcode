#pragma once

#include <numeric>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int maxA(int n) {
    std::vector<int> dp(n + 1);
    std::iota(dp.begin(), dp.end(), 0);
    for (int i = 0; i <= n; ++i) {
      for (int j = i + 3; j <= n && j <= i + 6; ++j) {
        dp[j] = std::max(dp[j], (j - i - 1) * dp[i]);
      }
    }
    return dp.back();
  }
};
