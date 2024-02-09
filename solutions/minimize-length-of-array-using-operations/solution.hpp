#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minimumArrayLength(const std::vector<int> &nums) {
    const auto min = std::ranges::min(nums);
    if (std::ranges::find_if(nums, [=](int num) { return num % min > 0; }) !=
        nums.end()) {
      return 1;
    }
    return (std::ranges::count(nums, min) + 1) / 2;
  }
};
