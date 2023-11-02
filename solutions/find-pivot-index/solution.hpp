#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int pivotIndex(const std::vector<int> &nums) {
    int left = 0;
    int right = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      right += nums[i];
    }

    for (size_t i = 0; i < nums.size(); ++i) {
      right -= nums[i];
      if (left == right) {
        return i;
      }
      left += nums[i];
    }

    return -1;
  }
};
