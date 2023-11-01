#pragma once

#include <vector>

/*
  1863. Sum of All Subset XOR Totals
  https://leetcode.com/problems/sum-of-all-subset-xor-totals/
  Difficulty: Easy
  Tags: Array, Math, Backtracking, Bit Manipulation, Combinatorics
  Time:
  Space:
*/

class Solution {
public:
  static int subsetXORSum(const std::vector<int> &nums) {
    return subsetXORSum(0, 0, nums);
  }

private:
  static int subsetXORSum(size_t i, int xorTotal,
                          const std::vector<int> &nums) {
    if (i == nums.size()) {
      return xorTotal;
    }
    return subsetXORSum(i + 1, xorTotal, nums) +
           subsetXORSum(i + 1, xorTotal ^ nums[i], nums);
  }
};
