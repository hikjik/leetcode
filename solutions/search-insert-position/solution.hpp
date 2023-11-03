#pragma once

#include <ranges>
#include <vector>

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static int searchInsert(const std::vector<int> &nums, int target) {
    return std::ranges::lower_bound(nums, target) - nums.cbegin();
  }
};
