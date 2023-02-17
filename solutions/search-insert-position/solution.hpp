#pragma once

#include <vector>

class Solution {
public:
  static int searchInsert(const std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] >= target) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return left;
  }
};