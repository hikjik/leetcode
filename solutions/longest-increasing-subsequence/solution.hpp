#pragma once

#include <algorithm>
#include <vector>

/*
  300. Longest Increasing Subsequence
  https://leetcode.com/problems/longest-increasing-subsequence/
  Difficulty: Medium
  Tags: Array, Binary Search, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int lengthOfLIS(const std::vector<int> &nums) {
    std::vector<int> dp;
    for (auto a : nums) {
      auto it = std::lower_bound(dp.begin(), dp.end(), a);
      if (it == dp.end()) {
        dp.push_back(a);
      } else {
        *it = a;
      }
    }
    return dp.size();
  }
};
