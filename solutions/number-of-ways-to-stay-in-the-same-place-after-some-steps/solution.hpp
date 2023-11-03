#pragma once

#include <array>

// Time:
// Space:

class Solution {
private:
  static constexpr int kMod = 1e9 + 7;
  static constexpr int kMaxSteps = 500;

public:
  static int numWays(int steps, int arrLen) {
    std::array<int, kMaxSteps + 1> dp{1};
    while (steps--) {
      for (int i = 0, prev = 0; i < std::min(arrLen, steps + 1); ++i) {
        std::swap(prev, dp[i]);
        dp[i] = (0LL + prev + dp[i] + dp[i + 1]) % kMod;
      }
    }
    return dp[0];
  }
};
