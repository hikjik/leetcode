#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int smallestRangeII(std::vector<int> nums, int k) {
    std::sort(nums.begin(), nums.end());

    int gap = nums.back() - nums.front();
    for (size_t i = 0; i + 1 < nums.size(); ++i) {
      int min = std::min(nums.front() + k, nums[i + 1] - k);
      int max = std::max(nums.back() - k, nums[i] + k);
      gap = std::min(gap, max - min);
    }

    return gap;
  }
};
