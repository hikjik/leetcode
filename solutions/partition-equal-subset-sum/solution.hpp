#pragma once

#include <numeric>
#include <vector>

/*
  416. Partition Equal Subset Sum
  https://leetcode.com/problems/partition-equal-subset-sum/
  Difficulty: Medium
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static bool canPartition(const std::vector<int> &nums) {
    const auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) {
      return false;
    }

    const int half = sum / 2;
    std::vector<bool> dp(half + 1, false);
    dp[0] = true;

    for (auto num : nums) {
      for (int i = half; i >= num; --i) {
        dp[i] = dp[i] | dp[i - num];
      }
    }

    return dp.back();
  }
};
