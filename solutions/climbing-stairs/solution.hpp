#pragma once

#include <utility>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int climbStairs(int n) {
    int a = 1, b = 1;
    for (int i = 1; i < n; ++i) {
      a = std::exchange(b, a + b);
    }
    return b;
  }
};
