#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int arraySign(std::vector<int> nums) {
    int sign = 1;
    for (auto num : nums) {
      if (!num) {
        sign = 0;
      }
      if (num < 0) {
        sign *= -1;
      }
    }
    return sign;
  }
};
