#pragma once

// Time:
// Space:

class Solution {
public:
  static int numberOfSteps(int num) {
    if (!num) {
      return 0;
    }

    const auto subtracts = __builtin_popcount(num);
    const auto shifts = 32 - __builtin_clz(num) - 1;
    return subtracts + shifts;
  }
};
