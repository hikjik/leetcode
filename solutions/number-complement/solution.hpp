#pragma once

/*
  476. Number Complement
  https://leetcode.com/problems/number-complement/
  Difficulty: Easy
  Tags: Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int findComplement(int num) {
    return ((1LL << (32 - __builtin_clz(num))) - 1) ^ num;
  }
};
