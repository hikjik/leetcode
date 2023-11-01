#pragma once

#include <cstdint>

/*
  191. Number of 1 Bits
  https://leetcode.com/problems/number-of-1-bits/
  Difficulty: Easy
  Tags: Divide and Conquer, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int hammingWeight(std::uint32_t n) { return __builtin_popcount(n); }
};
