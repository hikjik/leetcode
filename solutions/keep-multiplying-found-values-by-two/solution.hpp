#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int findFinalValue(std::vector<int> nums, int original) {
    std::sort(nums.begin(), nums.end());
    for (auto a : nums) {
      if (a == original) {
        original <<= 1;
      }
    }
    return original;
  }
};
