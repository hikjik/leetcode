#pragma once

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  static int coinChange(const std::vector<int> &coins, int amount) {
    std::vector<int> dp(amount + 1, INT_MAX - 1);
    dp[0] = 0;
    for (int i = 1; i < amount + 1; i++) {
      for (auto c : coins) {
        if (i - c >= 0) {
          dp[i] = std::min(dp[i], dp[i - c] + 1);
        }
      }
    }
    return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
  }
};
