#pragma once

#include <vector>

// Time: O(N^(1.5))
// Space: O(N)

class Solution {
public:
  static bool winnerSquareGame(int n) {
    std::vector<bool> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        if (!dp[i - j * j]) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};
