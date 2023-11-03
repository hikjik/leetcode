#pragma once

// Time:
// Space:

class Solution {
public:
  static int alternateDigitSum(int n) {
    int sum = 0, sign = 1;
    for (auto i = n; i; i /= 10) {
      sign *= -1;
      sum += sign * i % 10;
    }
    return sign * sum;
  }
};
