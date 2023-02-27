#pragma once

#include <vector>

class Solution {
public:
  static int findMin(const std::vector<int> &nums) {
    size_t left = 0, right = nums.size() - 1;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      if (nums[middle] < nums[right]) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return nums[left];
  }
};
