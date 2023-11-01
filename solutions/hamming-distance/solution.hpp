#pragma once

/*
  461. Hamming Distance
  https://leetcode.com/problems/hamming-distance/
  Difficulty: Easy
  Tags: Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int hammingDistance(int x, int y) { return __builtin_popcount(x ^ y); }
};
