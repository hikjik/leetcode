#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool hasTrailingZeros(const std::vector<int> &nums) {
    return std::ranges::count_if(nums, [](int a) { return !(a & 1); }) > 1;
  }
};
