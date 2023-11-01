#pragma once

/*
  201. Bitwise AND of Numbers Range
  https://leetcode.com/problems/bitwise-and-of-numbers-range/
  Difficulty: Medium
  Tags: Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left != right) {
      left >>= 1, right >>= 1;
      ++shift;
    }
    return left << shift;
  }
};
