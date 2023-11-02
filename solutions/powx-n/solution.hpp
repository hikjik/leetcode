#pragma once

#include <cmath>

// Time:
// Space:

class Solution {
public:
  static double myPow(double x, int n) {
    long long nn = std::abs(n);

    double res = 1;
    while (nn) {
      if (nn & 1) {
        res *= x;
      }
      x *= x;
      nn >>= 1;
    }

    return n < 0 ? 1 / res : res;
  }
};