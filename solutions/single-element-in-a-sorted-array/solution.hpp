#pragma once

#include <vector>

/*
  540. Single Element in a Sorted Array
  https://leetcode.com/problems/single-element-in-a-sorted-array/
  Difficulty: Medium
  Tags: Array, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static int singleNonDuplicate(const std::vector<int> &nums) {
    size_t left = 0;
    size_t right = nums.size() - 1;
    while (left < right) {
      const auto middle = (left + (right - left) / 2) & ~1;
      if (nums[middle] != nums[middle + 1]) {
        right = middle;
      } else {
        left = middle + 2;
      }
    }
    return nums[left];
  }
};
