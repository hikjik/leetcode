#pragma once

#include <vector>

/*
  896. Monotonic Array
  https://leetcode.com/problems/monotonic-array/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static bool isMonotonic(const std::vector<int> &nums) {
    bool increasing = true, decreasing = true;
    for (size_t i = 1; i < nums.size(); i++) {
      increasing &= nums[i - 1] >= nums[i];
      decreasing &= nums[i - 1] <= nums[i];
    }
    return increasing || decreasing;
  }
};
