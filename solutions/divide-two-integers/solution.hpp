#pragma once

#include <climits>
#include <cmath>

// Time: O(log^2N)
// Space: O(1)

class Solution {
public:
  static int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }

    long a = std::labs(dividend), b = std::labs(divisor);
    long quotient = 0;
    while (a >= b) {
      int x = 0;
      while (a >= b << x) {
        quotient += 1 << x;
        a -= b << x;
        ++x;
      }
    }
    return dividend < 0 != divisor < 0 ? -quotient : quotient;
  }
};
