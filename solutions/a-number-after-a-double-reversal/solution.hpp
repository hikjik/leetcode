#pragma once

/*
  2119. A Number After a Double Reversal
  https://leetcode.com/problems/a-number-after-a-double-reversal/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static bool isSameAfterReversals(int num) { return !num || num % 10 != 0; }
};
