#pragma once

#include <bit>
#include <climits>
#include <cmath>
#include <vector>

// Time: O(M2^M)
// Space: O(2^M)

namespace memo {

// Time: O(M2^M)
// Space: O(2^M)
class Solution {
public:
  static int assignBikes(const std::vector<std::vector<int>> &workers,
                         const std::vector<std::vector<int>> &bikes) {
    const int m = bikes.size();
    std::vector<int> memo(1 << m, INT_MAX);
    return assignBikes(0, workers, bikes, &memo);
  }

private:
  static int assignBikes(unsigned mask,
                         const std::vector<std::vector<int>> &workers,
                         const std::vector<std::vector<int>> &bikes,
                         std::vector<int> *memo) {
    const int i = std::popcount(mask);
    if (i == std::ssize(workers)) {
      return 0;
    }
    auto &ans = (*memo)[mask];
    if (ans == INT_MAX) {
      for (int j = 0; j < std::ssize(bikes); ++j) {
        if (mask >> j & 1) {
          continue;
        }
        ans =
            std::min(ans, distance(workers[i], bikes[j]) +
                              assignBikes(mask | 1 << j, workers, bikes, memo));
      }
    }
    return ans;
  }

  static int distance(const std::vector<int> &p1, const std::vector<int> &p2) {
    return std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);
  }
};

} // namespace memo

namespace dp {

// Time: O(M2^M)
// Space: O(2^M)
class Solution {
public:
  static int assignBikes(const std::vector<std::vector<int>> &workers,
                         const std::vector<std::vector<int>> &bikes) {
    const int m = bikes.size();
    std::vector<int> dp(1 << m, INT_MAX);
    for (int mask = std::ssize(dp) - 1; mask >= 0; --mask) {
      const int i = std::popcount(mask * 1u);
      if (i > std::ssize(workers)) {
        continue;
      }
      if (i == std::ssize(workers)) {
        dp[mask] = 0;
      }

      for (int j = 0; j < std::ssize(bikes); ++j) {
        if (mask >> j & 1) {
          dp[mask ^ 1 << j] = std::min(
              dp[mask ^ 1 << j], distance(workers[i - 1], bikes[j]) + dp[mask]);
        }
      }
    }
    return dp[0];
  }

private:
  static int distance(const std::vector<int> &p1, const std::vector<int> &p2) {
    return std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);
  }
};

} // namespace dp
