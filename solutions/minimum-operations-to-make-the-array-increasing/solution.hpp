#pragma once

#include <vector>

/*
  1827. Minimum Operations to Make the Array Increasing
  https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
  Difficulty: Easy
  Tags: Array, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int minOperations(const std::vector<int> &nums) {
    int ops = 0;
    for (int prev = 0; auto a : nums) {
      ops += std::max(0, prev - a + 1);
      prev = std::max(a, prev + 1);
    }
    return ops;
  }
};
