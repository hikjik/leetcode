#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int dominantIndex(std::vector<int> nums) {
    const auto idx = std::max_element(nums.begin(), nums.end()) - nums.begin();
    std::partial_sort(nums.begin(), nums.begin() + 2, nums.end(),
                      std::greater<int>());
    return nums[0] >= nums[1] * 2 ? idx : -1;
  }
};
