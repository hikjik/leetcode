#pragma once

#include <vector>

class Solution {
public:
  static int repeatedNTimes(const std::vector<int> &nums) {
    for (size_t i = 0; i + 1 < nums.size(); ++i) {
      if (nums[i] == nums[i + 1]) {
        return nums[i];
      }
    }
    return nums.back() == nums[1] ? nums[1] : nums[0];
  }
};
