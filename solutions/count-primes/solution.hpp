#pragma once

#include <ranges>

// Time: O(NloglogN)
// Space: O(N)
// Notes: [Sieve of Eratosthenes](https://w.wiki/cYa)

class Solution {
public:
  static int countPrimes(int n) {
    if (n <= 1) {
      return false;
    }

    std::vector<bool> dp(n, true);
    dp[0] = dp[1] = false;
    for (int i = 2; i * i < n; ++i) {
      if (dp[i]) {
        for (int j = i * i; j < n; j += i) {
          dp[j] = false;
        }
      }
    }
    return std::ranges::count(dp, true);
  }
};
