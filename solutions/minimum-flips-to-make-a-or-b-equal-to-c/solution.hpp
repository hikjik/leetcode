#pragma once

/*
  1318. Minimum Flips to Make a OR b Equal to c
  https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
  Difficulty: Medium
  Tags: Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int minFlips(int a, int b, int c) {
    return __builtin_popcount((a | b) ^ c) + __builtin_popcount(a & b & ~c);
  }
};
