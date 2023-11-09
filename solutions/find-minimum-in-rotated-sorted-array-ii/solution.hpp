#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int findMin(const std::vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      if (nums[middle] == nums[right]) {
        --right;
      } else if (nums[middle] < nums[right]) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return nums[left];
  }
};
