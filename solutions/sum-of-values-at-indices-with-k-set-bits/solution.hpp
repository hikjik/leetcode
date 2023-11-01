#pragma once

#include <vector>

/*
  2859. Sum of Values at Indices With K Set Bits
  https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/
  Difficulty: Easy
  Tags: Array, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int sumIndicesWithKSetBits(const std::vector<int> &nums, int k) {
    int sum = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (__builtin_popcount(i) == k) {
        sum += nums[i];
      }
    }
    return sum;
  }
};
