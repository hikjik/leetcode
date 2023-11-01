#pragma once

#include <algorithm>
#include <vector>

/*
  976. Largest Perimeter Triangle
  https://leetcode.com/problems/largest-perimeter-triangle/
  Difficulty: Easy
  Tags: Array, Math, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int largestPerimeter(std::vector<int> nums) {
    std::sort(nums.rbegin(), nums.rend());
    for (size_t i = 0; i < nums.size() - 2; ++i) {
      if (nums[i] < nums[i + 1] + nums[i + 2]) {
        return nums[i] + nums[i + 1] + nums[i + 2];
      }
    }
    return 0;
  }
};