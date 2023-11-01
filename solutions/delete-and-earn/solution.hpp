#pragma once

#include <algorithm>
#include <array>
#include <vector>

/*
  740. Delete and Earn
  https://leetcode.com/problems/delete-and-earn/
  Difficulty: Medium
  Tags: Array, Hash Table, Dynamic Programming
  Time:
  Space:
*/

class Solution {
  static const int MAX_VALUE = 1e4;

public:
  static int deleteAndEarn(std::vector<int> nums) {
    std::array<int, MAX_VALUE + 1> dp = {};

    for (auto num : nums) {
      dp[num] += num;
    }

    for (size_t i = 3; i < dp.size(); ++i) {
      dp[i] += std::max(dp[i - 2], dp[i - 3]);
    }

    return std::max(dp[MAX_VALUE], dp[MAX_VALUE - 1]);
  }
};
