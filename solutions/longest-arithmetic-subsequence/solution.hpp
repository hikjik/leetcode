#pragma once

#include <algorithm>
#include <vector>

/*
  1027. Longest Arithmetic Subsequence
  https://leetcode.com/problems/longest-arithmetic-subsequence/
  Difficulty: Medium
  Tags: Array, Hash Table, Binary Search, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int longestArithSeqLength(const std::vector<int> &nums) {
    std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(1001, 0));

    int max_length = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        const int k = nums[i] - nums[j] + 500;
        dp[i][k] = std::max(dp[j][k] + 1, 2);
        max_length = std::max(max_length, dp[i][k]);
      }
    }
    return max_length;
  }
};
