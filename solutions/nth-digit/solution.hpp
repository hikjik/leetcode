#pragma once

#include <string>

// Time: O(logN)
// Space: O(logN)

class Solution {
public:
  static int findNthDigit(int n) {
    int length = 1;
    long long pow10 = 1;
    while (9 * length * pow10 < n) {
      n -= 9 * length * pow10;
      ++length;
      pow10 *= 10;
    }

    const auto q = (n - 1) / length, r = (n - 1) % length;
    return std::to_string(pow10 + q)[r] - '0';
  }
};
