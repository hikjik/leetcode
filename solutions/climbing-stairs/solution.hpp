#pragma once

// Time:
// Space:

class Solution {
public:
  static int climbStairs(int n) {
    int a = 1;
    int b = 1;
    for (int i = 1; i < n; ++i) {
      int sum = a + b;
      a = b;
      b = sum;
    }
    return b;
  }
};