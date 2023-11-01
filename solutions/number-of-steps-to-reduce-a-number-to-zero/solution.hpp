#pragma once

/*
  1342. Number of Steps to Reduce a Number to Zero
  https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
  Difficulty: Easy
  Tags: Math, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int numberOfSteps(int num) {
    if (!num) {
      return 0;
    }

    const auto subtracts = __builtin_popcount(num);
    const auto shifts = 32 - __builtin_clz(num) - 1;
    return subtracts + shifts;
  }
};
