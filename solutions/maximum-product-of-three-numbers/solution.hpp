#pragma once

#include <algorithm>
#include <vector>

/*
  628. Maximum Product of Three Numbers
  https://leetcode.com/problems/maximum-product-of-three-numbers/
  Difficulty: Easy
  Tags: Array, Math, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int maximumProduct(std::vector<int> nums) {
    std::vector<int> mins(2);
    std::partial_sort_copy(nums.begin(), nums.end(), mins.begin(), mins.end());
    std::partial_sort(nums.begin(), nums.begin() + 3, nums.end(),
                      std::greater<>());
    return std::max(nums[0] * nums[1] * nums[2], nums[0] * mins[0] * mins[1]);
  }
};
