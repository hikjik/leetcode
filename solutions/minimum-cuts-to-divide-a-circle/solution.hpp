#pragma once

/*
  2481. Minimum Cuts to Divide a Circle
  https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/
  Difficulty: Easy
  Tags: Math, Geometry
  Time:
  Space:
*/

class Solution {
public:
  static int numberOfCuts(int n) { return n == 1 ? 0 : n & 1 ? n : n / 2; }
};
