#pragma once

/*
  2220. Minimum Bit Flips to Convert Number
  https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
  Difficulty: Easy
  Tags: Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int minBitFlips(int start, int goal) {
    return __builtin_popcount(start ^ goal);
  }
};
