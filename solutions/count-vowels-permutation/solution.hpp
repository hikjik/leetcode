#pragma once

#include <array>
#include <numeric>
#include <vector>

class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int countVowelPermutation(int n) {
    std::array<long long, 5> dp{1, 1, 1, 1, 1};
    while (--n) {
      dp = {
          dp[1],
          (dp[0] + dp[2]) % kMod,
          (dp[0] + dp[1] + dp[3] + dp[4]) % kMod,
          (dp[2] + dp[4]) % kMod,
          dp[0],
      };
    }
    return std::accumulate(dp.begin(), dp.end(), 0LL) % kMod;
  }
};
