#pragma once

/*
  868. Binary Gap
  https://leetcode.com/problems/binary-gap/
  Difficulty: Easy
  Tags: Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int binaryGap(int n) {
    int gap = 0;
    for (int x = n >> 1 + __builtin_ctz(n); x; x >>= 1 + __builtin_ctz(x)) {
      gap = std::max(gap, 1 + __builtin_ctz(x));
    }
    return gap;
  }
};
