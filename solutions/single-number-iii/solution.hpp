#pragma once

#include <vector>

/*
  260. Single Number III
  https://leetcode.com/problems/single-number-iii/
  Difficulty: Medium
  Tags: Array, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> singleNumber(const std::vector<int> &nums) {
    int xor_sum = 0;
    for (auto num : nums) {
      xor_sum ^= num;
    }

    int pos = __builtin_ctz(xor_sum);

    int first_num = 0;
    for (auto num : nums) {
      if ((num >> pos) & 1) {
        first_num ^= num;
      }
    }
    return {xor_sum ^ first_num, first_num};
  }
};
