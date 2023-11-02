#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int averageValue(const std::vector<int> &nums) {
    int sum = 0, cnt = 0;
    for (auto a : nums) {
      if (a % 6 == 0) {
        ++cnt, sum += a;
      }
    }
    return cnt ? sum / cnt : 0;
  }
};
