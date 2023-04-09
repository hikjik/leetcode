#pragma once

#include <numeric>

class Solution {
public:
  static int nthUglyNumber(int n, long long a, long long b, long long c) {
    int left = 1, right = 2 * 1e9;
    while (left < right) {
      int middle = left + (right - left) / 2;
      const auto cnt = middle / a + middle / b + middle / c +
                       middle / std::lcm(a, std::lcm(b, c)) -
                       middle / std::lcm(a, b) - middle / std::lcm(a, c) -
                       middle / std::lcm(b, c);
      cnt < n ? left = middle + 1 : right = middle;
    }
    return left;
  }
};
