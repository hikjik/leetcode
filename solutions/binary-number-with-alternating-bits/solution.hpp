#pragma once

/*
  693. Binary Number with Alternating Bits
  https://leetcode.com/problems/binary-number-with-alternating-bits/
  Difficulty: Easy
  Tags: Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static bool hasAlternatingBits(int n) {
    n ^= n >> 2;
    return !(n & (n - 1));
  }
};
