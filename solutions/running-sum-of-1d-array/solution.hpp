#pragma once

#include <vector>

/*
  1480. Running Sum of 1d Array
  https://leetcode.com/problems/running-sum-of-1d-array/
  Difficulty: Easy
  Tags: Array, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> runningSum(const std::vector<int> &nums) {
    std::vector<int> running_sum(nums);
    for (size_t i = 1; i < nums.size(); ++i) {
      running_sum[i] += running_sum[i - 1];
    }
    return running_sum;
  }
};
