#pragma once

#include <cmath>

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static bool isArmstrong(int n) {
    const int k = std::log10(n) + 1;
    int sum = 0;
    for (int i = n; i; i /= 10) {
      sum += std::pow(i % 10, k);
    }
    return n == sum;
  }
};
