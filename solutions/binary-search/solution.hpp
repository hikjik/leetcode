#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int search(const std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] == target) {
        return middle;
      }

      if (nums[middle] > target) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return -1;
  }
};