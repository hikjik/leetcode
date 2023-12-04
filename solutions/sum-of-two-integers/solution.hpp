#pragma once

#include <cmath>

// Time: O(1)
// Space: O(1)

namespace math {

// Time: O(1)
// Space: O(1)
class Solution {
public:
  static int getSum(int a, int b) {
    return std::log2(std::pow(2, a) * std::pow(2, b));
  }
};

} // namespace math

namespace bits {

// Time: O(1)
// Space: O(1)
class Solution {
public:
  static int getSum(int a, int b) {
    while (b) {
      const int carry = a & b;
      a ^= b;
      b = carry << 1;
    }
    return a;
  }
};

} // namespace bits
