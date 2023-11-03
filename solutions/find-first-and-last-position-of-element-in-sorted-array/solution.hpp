#pragma once

#include <vector>

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static std::vector<int> searchRange(const std::vector<int> &nums,
                                      int target) {
    auto [lb, ub] = std::equal_range(nums.cbegin(), nums.cend(), target);
    if (lb == nums.end() || *lb != target) {
      return {-1, -1};
    }
    return {
        static_cast<int>(std::distance(nums.cbegin(), lb)),
        static_cast<int>(std::distance(nums.cbegin(), std::prev(ub))),
    };
  }
};
