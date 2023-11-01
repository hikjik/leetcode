#pragma once

/*
  231. Power of Two
  https://leetcode.com/problems/power-of-two/
  Difficulty: Easy
  Tags: Math, Bit Manipulation, Recursion
  Time:
  Space:
*/

class Solution {
public:
  static bool isPowerOfTwo(int n) { return n > 0 && !(n & (n - 1)); };
};
