#pragma once

#include <vector>

class Solution {
public:
  static int sumIndicesWithKSetBits(const std::vector<int> &nums, int k) {
    int sum = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (__builtin_popcount(i) == k) {
        sum += nums[i];
      }
    }
    return sum;
  }
};
