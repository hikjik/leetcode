#pragma once

#include <algorithm>
#include <vector>

/*
  189. Rotate Array
  https://leetcode.com/problems/rotate-array/
  Difficulty: Medium
  Tags: Array, Math, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static void rotate(std::vector<int> &nums, int k) {
    int l = nums.size() - k % nums.size();
    std::reverse(nums.begin(), nums.begin() + l);
    std::reverse(nums.begin() + l, nums.end());
    std::reverse(nums.begin(), nums.end());
  }
};
