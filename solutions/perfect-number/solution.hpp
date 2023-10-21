#pragma once

#include <vector>

class Solution {
public:
  static bool checkPerfectNumber(int num) {
    const std::vector<int> primes{2, 3, 5, 7, 13};
    for (auto p : primes) {
      if (((1 << p) - 1) * ((1 << (p - 1))) == num) {
        return true;
      }
    }
    return false;
  }
};
