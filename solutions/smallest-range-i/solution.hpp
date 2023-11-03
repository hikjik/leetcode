#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int smallestRangeI(const std::vector<int> &nums, int k) {
    auto [it_min, it_max] = std::minmax_element(nums.begin(), nums.end());
    return std::max(0, *it_max - *it_min - 2 * k);
  }
};
