#pragma once

#include <vector>

class Solution {
public:
  static int countGoodStrings(int low, int high, int zero, int one) {
    static const int kMod = 1e9 + 7;

    std::vector<int> dp(high + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < high + 1; ++i) {
      if (i - zero >= 0) {
        dp[i] += dp[i - zero];
      }
      if (i - one >= 0) {
        dp[i] += dp[i - one];
      }
      dp[i] %= kMod;
    }

    int sum = 0;
    for (int i = low; i <= high; ++i) {
      sum += dp[i];
      sum %= kMod;
    }
    return sum;
  }
};
