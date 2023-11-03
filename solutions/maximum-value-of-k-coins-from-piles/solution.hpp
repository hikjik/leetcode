#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxValueOfCoins(const std::vector<std::vector<int>> &piles,
                             int k) {
    std::vector<int> dp(k + 1, 0);
    for (const auto &pile : piles) {
      for (size_t coins = k; coins; --coins) {
        int sum = 0;
        for (size_t i = 0; i < std::min(coins, pile.size()); ++i) {
          sum += pile[i];
          dp[coins] = std::max(dp[coins], dp[coins - 1 - i] + sum);
        }
      }
    }
    return dp[k];
  }
};
