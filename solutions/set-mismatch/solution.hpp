#pragma once

#include <vector>

/*
  645. Set Mismatch
  https://leetcode.com/problems/set-mismatch/
  Difficulty: Easy
  Tags: Array, Hash Table, Bit Manipulation, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> findErrorNums(std::vector<int> nums) {
    const int n = nums.size();

    for (int i = 0; i < n;) {
      if (nums[i] != nums[nums[i] - 1]) {
        std::swap(nums[i], nums[nums[i] - 1]);
      } else {
        ++i;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        return {nums[i], i + 1};
      }
    }

    throw;
  }
};
