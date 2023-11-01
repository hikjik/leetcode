#pragma once

#include <algorithm>
#include <vector>

/*
  16. 3Sum Closest
  https://leetcode.com/problems/3sum-closest/
  Difficulty: Medium
  Tags: Array, Two Pointers, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int threeSumClosest(std::vector<int> nums, int target) {
    std::sort(nums.begin(), nums.end());

    int closest_sum = nums[0] + nums[1] + nums[2];
    for (size_t i = 0; i + 2 < nums.size(); ++i) {
      auto l = i + 1, r = nums.size() - 1;
      while (l < r) {
        const auto sum = nums[i] + nums[l] + nums[r];
        if (abs(closest_sum - target) > abs(sum - target)) {
          closest_sum = sum;
        }
        sum > target ? --r : ++l;
      }
    }
    return closest_sum;
  }
};
