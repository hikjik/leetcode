#pragma once

#include <algorithm>
#include <vector>

/*
  2529. Maximum Count of Positive Integer and Negative Integer
  https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
  Difficulty: Easy
  Tags: Array, Binary Search, Counting
  Time:
  Space:
*/

class Solution {
public:
  static int maximumCount(const std::vector<int> &nums) {
    const auto range = std::equal_range(nums.begin(), nums.end(), 0);
    return std::max(range.first - nums.begin(), nums.end() - range.second);
  }
};
