#pragma once

#include <cmath>

class Solution {
public:
  static bool isThree(int n) {
    const int p = std::sqrt(n);
    return p * p == n && isPrime(p);
  }

private:
  static bool isPrime(int n) {
    if (n < 2) {
      return false;
    }
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};
