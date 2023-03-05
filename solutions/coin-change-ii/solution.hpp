#pragma once

#include <vector>

class Solution {
public:
  static int change(int amount, const std::vector<int> &coins) {
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (auto c : coins) {
      for (int i = 1; i < amount + 1; i++) {
        if (i - c >= 0) {
          dp[i] += dp[i - c];
        }
      }
    }
    return dp[amount];
  }
};
