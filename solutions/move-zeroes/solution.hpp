#pragma once

#include <algorithm>
#include <vector>

/*
  283. Move Zeroes
  https://leetcode.com/problems/move-zeroes/
  Difficulty: Easy
  Tags: Array, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static void moveZeroes(std::vector<int> &nums) {
    auto it = nums.begin();
    for (auto num : nums) {
      if (num) {
        *it++ = num;
      }
    }
    std::fill(it, nums.end(), 0);
  }
};
