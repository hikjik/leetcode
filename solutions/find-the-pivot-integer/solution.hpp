#pragma once

#include <cmath>

/*
  2485. Find the Pivot Integer
  https://leetcode.com/problems/find-the-pivot-integer/
  Difficulty: Easy
  Tags: Math, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static int pivotInteger(int n) {
    const int sum = (n + 1) * n / 2;
    const int sqrt = std::sqrt(sum);
    return sqrt * sqrt == sum ? sqrt : -1;
  }
};
