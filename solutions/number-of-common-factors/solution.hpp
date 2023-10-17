#pragma once

#include <cmath>
#include <numeric>

class Solution {
public:
  static int commonFactors(int a, int b) {
    return countDivisors(std::gcd(a, b));
  }

private:
  static int countDivisors(int n) {
    int cnt = 0;
    for (int d = 1; d <= std::sqrt(n); ++d) {
      if (n % d == 0) {
        cnt += d == n / d ? 1 : 2;
      }
    }
    return cnt;
  }
};
