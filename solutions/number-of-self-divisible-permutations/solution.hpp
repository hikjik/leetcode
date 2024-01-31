#pragma once

#include <bit>
#include <functional>
#include <numeric>
#include <vector>

// Time: O(N2^N)
// Space: O(2^N)

namespace memo {

// Time: O(N2^N)
// Space: O(2^N)
class Solution {
public:
  static int selfDivisiblePermutationCount(int n) {
    std::vector<int> memo(1 << n, -1);

    std::function<int(unsigned)> countPermutations = [&](unsigned mask) {
      const auto i = std::popcount(mask);
      if (i == n) {
        return 1;
      }
      if (memo[mask] != -1) {
        return memo[mask];
      }

      memo[mask] = 0;
      for (int j = 0; j < n; ++j) {
        if (mask & 1 << j) {
          continue;
        }
        if (std::gcd(i + 1, j + 1) == 1) {
          memo[mask] += countPermutations(mask | 1 << j);
        }
      }
      return memo[mask];
    };

    return countPermutations(0);
  }
};

} // namespace memo

namespace dp {

// Time: O(N2^N)
// Space: O(2^N)
class Solution {
public:
  static int selfDivisiblePermutationCount(int n) {
    std::vector<int> dp(1 << n);
    dp[0] = 1;
    for (unsigned mask = 0; mask < dp.size(); ++mask) {
      const auto i = std::popcount(mask);
      for (int j = 0; j < n; ++j) {
        if (!(mask & 1 << j) && std::gcd(i + 1, j + 1) == 1) {
          dp[mask | 1 << j] += dp[mask];
        }
      }
    }
    return dp.back();
  }
};

} // namespace dp
