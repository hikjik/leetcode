#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int maximumCount(const std::vector<int> &nums) {
    const auto range = std::equal_range(nums.begin(), nums.end(), 0);
    return std::max(range.first - nums.begin(), nums.end() - range.second);
  }
};
