#pragma once

#include <algorithm>
#include <vector>

/*
  2460. Apply Operations to an Array
  https://leetcode.com/problems/apply-operations-to-an-array/
  Difficulty: Easy
  Tags: Array, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> applyOperations(std::vector<int> nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        nums[i - 1] *= 2, nums[i] = 0;
      }
    }
    std::stable_partition(nums.begin(), nums.end(), [](int a) { return a; });
    return nums;
  }
};
