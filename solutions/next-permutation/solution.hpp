#pragma once

#include <algorithm>
#include <vector>

/*
  31. Next Permutation
  https://leetcode.com/problems/next-permutation/
  Difficulty: Medium
  Tags: Array, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static void nextPermutation(std::vector<int> &nums) {
    std::next_permutation(nums.begin(), nums.end());
  }
};
