#pragma once

#include <cmath>
#include <vector>

// Time: O(TlogT)
// Space: O(T)

class Solution {
public:
  static int racecar(int target) {
    std::vector<int> dp(target + 1);
    for (int n = 1; n <= target; ++n) {
      const int i = std::log2(n) + 1;
      const int l = (1 << (i - 1)) - 1, r = (1 << i) - 1;
      if (n == r) {
        dp[r] = i;
      } else {
        dp[n] = i + 1 + dp[r - n];
        for (int j = 0, m = 0; m < l; m = (1 << ++j) - 1) {
          dp[n] = std::min(dp[n], dp[l] + 1 + dp[m] + 1 + dp[n - (l - m)]);
        }
      }
    }
    return dp.back();
  }
};
