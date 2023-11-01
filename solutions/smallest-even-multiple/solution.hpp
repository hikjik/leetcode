#pragma once

#include <numeric>

/*
  2413. Smallest Even Multiple
  https://leetcode.com/problems/smallest-even-multiple/
  Difficulty: Easy
  Tags: Math, Number Theory
  Time:
  Space:
*/

class Solution {
public:
  static int smallestEvenMultiple(int n) { return std::lcm(n, 2); }
};
