#pragma once

#include <vector>

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static int findPeakElement(const std::vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      nums[middle] < nums[middle + 1] ? left = middle + 1 : right = middle;
    }
    return left;
  }
};
