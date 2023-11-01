#pragma once

/*
  1009. Complement of Base 10 Integer
  https://leetcode.com/problems/complement-of-base-10-integer/
  Difficulty: Easy
  Tags: Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int bitwiseComplement(int n) {
    return n ? ((1 << (32 - __builtin_clz(n))) - 1) ^ n : 1;
  }
};
