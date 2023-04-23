#pragma once

#include <cmath>

class Solution {
private:
  static inline const int kMaxThreePower = static_cast<int>(std::pow(3, 19));

public:
  static bool isPowerOfThree(int n) { return n > 0 && kMaxThreePower % n == 0; }
};
