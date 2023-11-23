#pragma once

#include <queue>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int peopleAwareOfSecret(int n, int delay, int forget) {
    std::vector<int> dp(n);
    dp[0] = 1;
    long long share = 0;
    for (int i = 1; i < n; ++i) {
      if (i - delay >= 0) {
        share += dp[i - delay];
      }
      if (i - forget >= 0) {
        share -= dp[i - forget];
      }
      dp[i] = share = (share + kMod) % kMod;
    }
    return accumulate(dp.end() - forget, dp.end(), 0LL) % kMod;
  }
};
