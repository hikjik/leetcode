#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int countElements(const std::vector<int> &nums) {
    const auto [it_min, it_max] = std::minmax_element(nums.begin(), nums.end());
    const auto min = *it_min, max = *it_max;
    return std::count_if(nums.begin(), nums.end(),
                         [min, max](int a) { return min < a && a < max; });
  }
};
