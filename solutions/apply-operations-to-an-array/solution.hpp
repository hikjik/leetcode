#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> applyOperations(std::vector<int> nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        nums[i - 1] *= 2, nums[i] = 0;
      }
    }
    std::stable_partition(nums.begin(), nums.end(), [](int a) { return a; });
    return nums;
  }
};
