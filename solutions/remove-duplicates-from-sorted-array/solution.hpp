#pragma once

#include <vector>

/*
  26. Remove Duplicates from Sorted Array
  https://leetcode.com/problems/remove-duplicates-from-sorted-array/
  Difficulty: Easy
  Tags: Array, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static int removeDuplicates(std::vector<int> &nums) {
    size_t size = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (i < 1 || nums[i] != nums[size - 1]) {
        nums[size++] = nums[i];
      }
    }
    return size;
  }
};
