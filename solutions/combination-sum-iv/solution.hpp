#pragma once

#include <vector>

/*
  377. Combination Sum IV
  https://leetcode.com/problems/combination-sum-iv/
  Difficulty: Medium
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int combinationSum4(const std::vector<int> &nums, int target) {
    std::vector<unsigned long long> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < target + 1; i++) {
      for (auto c : nums) {
        if (i - c >= 0) {
          dp[i] += dp[i - c];
        }
      }
    }
    return dp[target];
  }
};
