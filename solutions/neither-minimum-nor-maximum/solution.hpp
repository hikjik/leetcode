#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int findNonMinOrMax(std::vector<int> nums) {
    if (nums.size() < 3) {
      return -1;
    }
    std::sort(nums.begin(), nums.begin() + 3);
    return nums[1];
  }
};
