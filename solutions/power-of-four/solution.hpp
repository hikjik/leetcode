#pragma once

/*
  342. Power of Four
  https://leetcode.com/problems/power-of-four/
  Difficulty: Easy
  Tags: Math, Bit Manipulation, Recursion
  Time:
  Space:
*/

class Solution {
public:
  static bool isPowerOfFour(int n) {
    return isPowerOfTwo(n) && (n - 1) % 3 == 0;
  }

  static bool isPowerOfTwo(int n) { return n > 0 && !(n & (n - 1)); };
};
