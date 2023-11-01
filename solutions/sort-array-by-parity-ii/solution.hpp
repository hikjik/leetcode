#pragma once

#include <vector>

/*
  922. Sort Array By Parity II
  https://leetcode.com/problems/sort-array-by-parity-ii/
  Difficulty: Easy
  Tags: Array, Two Pointers, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> sortArrayByParityII(const std::vector<int> &nums) {
    std::vector<int> ans(nums.size());
    for (int even = -2, odd = -1; auto a : nums) {
      ans[a & 1 ? odd += 2 : even += 2] = a;
    }
    return ans;
  }
};
