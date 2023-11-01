#pragma once

#include <vector>

/*
  1470. Shuffle the Array
  https://leetcode.com/problems/shuffle-the-array/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> shuffle(const std::vector<int> &nums, int n) {
    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
      ans.push_back(nums[i]);
      ans.push_back(nums[i + n]);
    }
    return ans;
  }
};
