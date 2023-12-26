#pragma once

#include <vector>

// Time: O(NKT)
// Space: O(T)

namespace memo {

// Time: O(NKT)
// Space: O(NT)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int numRollsToTarget(int n, int k, int target) {
    std::vector memo(target + 1, std::vector<int>(n + 1, -1));
    return numRollsToTarget(n, k, target, &memo);
  }

  static int numRollsToTarget(int n, int k, int target,
                              std::vector<std::vector<int>> *memo) {
    if (n == 1) {
      return k >= target;
    }
    auto &ans = (*memo)[target][n];
    if (ans == -1) {
      long long sum = 0;
      for (int i = 1; i <= k && i < target; ++i) {
        sum += numRollsToTarget(n - 1, k, target - i, memo);
      }
      ans = sum % kMod;
    }
    return ans;
  }
};

} // namespace memo

namespace dp {

// Time: O(NKT)
// Space: O(NT)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int numRollsToTarget(int n, int k, int target) {
    std::vector dp(n + 1, std::vector<int>(target + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int t = 0; t <= target; ++t) {
        long long sum = 0;
        for (int j = 1; j <= k && j <= t; ++j) {
          sum += dp[i - 1][t - j];
        }
        dp[i][t] = sum % kMod;
      }
    }
    return dp[n][target];
  }
};

} // namespace dp

namespace optimized {

// Time: O(NKT)
// Space: O(T)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int numRollsToTarget(int n, int k, int target) {
    std::vector<int> dp(target + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int t = target; t >= 0; --t) {
        long long sum = 0;
        for (int j = 1; j <= k && j <= t; ++j) {
          sum += dp[t - j];
        }
        dp[t] = sum % kMod;
      }
    }
    return dp.back();
  }
};

} // namespace optimized
