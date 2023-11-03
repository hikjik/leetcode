#pragma once

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int climbStairs(int n) {
    int a = 1, b = 1;
    for (int i = 1; i < n; ++i) {
      const auto sum = a + b;
      a = b, b = sum;
    }
    return b;
  }
};