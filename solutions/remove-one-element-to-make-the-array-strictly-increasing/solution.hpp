#pragma once

#include <vector>

/*
  1909. Remove One Element to Make the Array Strictly Increasing
  https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static bool canBeIncreasing(const std::vector<int> &nums) {
    const int n = nums.size();
    for (int i = 0, removed = 0; i + 1 < n; ++i) {
      if (nums[i] >= nums[i + 1]) {
        if (removed++) {
          return false;
        }

        if ((i > 0 && nums[i - 1] >= nums[i + 1]) &&
            (i + 2 < n && nums[i] >= nums[i + 2])) {
          return false;
        }
      }
    }
    return true;
  }
};
