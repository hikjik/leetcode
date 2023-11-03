#pragma once

#include <vector>

// Time: O(N) in worst case
// Space: O(1)

class Solution {
public:
  static bool search(const std::vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      const auto middle = left + (right - left) / 2;
      if (nums[middle] == target) {
        return true;
      }

      if (nums[left] == nums[middle] && nums[right] == nums[middle]) {
        ++left, --right;
        continue;
      }

      if (nums[left] <= nums[middle]) {
        if (nums[left] <= target && target < nums[middle]) {
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      } else {
        if (nums[middle] < target && target <= nums[right]) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }
    }

    return false;
  }
};
