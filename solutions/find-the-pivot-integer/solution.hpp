#pragma once

#include <cmath>

// Time:
// Space:

class Solution {
public:
  static int pivotInteger(int n) {
    const int sum = (n + 1) * n / 2;
    const int sqrt = std::sqrt(sum);
    return sqrt * sqrt == sum ? sqrt : -1;
  }
};
