#pragma once

#include <vector>

class Solution {
public:
  static int findPeakElement(const std::vector<int> &nums) {
    size_t left = 0, right = nums.size() - 1;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      if (nums[middle] < nums[middle + 1]) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }
    return left;
  }
};