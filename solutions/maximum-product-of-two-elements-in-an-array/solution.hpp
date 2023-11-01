#pragma once

#include <algorithm>
#include <vector>

/*
  1464. Maximum Product of Two Elements in an Array
  https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
  Difficulty: Easy
  Tags: Array, Sorting, Heap (Priority Queue)
  Time:
  Space:
*/

class Solution {
public:
  static int maxProduct(std::vector<int> nums) {
    std::partial_sort(nums.begin(), nums.begin() + 2, nums.end(),
                      std::greater<>());
    return (nums[0] - 1) * (nums[1] - 1);
  }
};
