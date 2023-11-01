#pragma once

/*
  343. Integer Break
  https://leetcode.com/problems/integer-break/
  Difficulty: Medium
  Tags: Math, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int integerBreak(int n) {
    if (n <= 3) {
      return n - 1;
    }

    int mult = 1;
    while (n > 4) {
      n -= 3;
      mult *= 3;
    }
    return mult * n;
  }
};
