#pragma once

#include <vector>

class Solution {
public:
  static int findMaxConsecutiveOnes(const std::vector<int> &nums) {
    int max = 0, sum = 0;
    for (auto a : nums) {
      sum = a ? sum + 1 : 0;
      max = std::max(max, sum);
    }
    return max;
  }
};
