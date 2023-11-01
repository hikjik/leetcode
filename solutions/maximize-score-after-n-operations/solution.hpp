#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

/*
  1799. Maximize Score After N Operations
  https://leetcode.com/problems/maximize-score-after-n-operations/
  Difficulty: Hard
  Tags: Array, Math, Dynamic Programming, Backtracking, Bit Manipulation,
        Number Theory, Bitmask
  Time:
  Space:
*/

class Solution {
public:
  static int maxScore(const std::vector<int> &nums) {
    const int n = nums.size();

    std::vector<std::vector<int>> gcd(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        gcd[i][j] = std::gcd(nums[i], nums[j]);
      }
    }

    std::vector<int> dp((1 << n), 0);
    for (int mask = 1; mask < (1 << n); ++mask) {
      if (__builtin_popcount(mask) & 1) {
        continue;
      }
      const auto operation_index = __builtin_popcount(mask) / 2;

      for (int i = 0; i < n; ++i) {
        if (!((mask >> i) & 1)) {
          continue;
        }

        for (int j = i + 1; j < n; ++j) {
          if (!((mask >> j) & 1)) {
            continue;
          }

          const auto score = operation_index * gcd[i][j];
          const auto new_mask = mask ^ (1 << i) ^ (1 << j);
          dp[mask] = std::max(dp[mask], score + dp[new_mask]);
        }
      }
    }
    return dp.back();
  }
};
