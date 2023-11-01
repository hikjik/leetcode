#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

/*
  1403. Minimum Subsequence in Non-Increasing Order
  https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
  Difficulty: Easy
  Tags: Array, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> minSubsequence(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end(), std::greater{});
    const auto half = std::accumulate(nums.begin(), nums.end(), 0) / 2;
    std::vector<int> ans;
    for (int i = 0, sum = 0; sum <= half; sum += nums[i++]) {
      ans.push_back(nums[i]);
    }
    return ans;
  }
};
