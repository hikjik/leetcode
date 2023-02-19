#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static bool canJump(std::vector<int> nums) {
    for (size_t j = 1; j < nums.size(); ++j) {
      if (nums[j - 1] > 0) {
        nums[j] = std::max(nums[j - 1] - 1, nums[j]);
      } else {
        return false;
      }
    }
    return true;
  }
};
