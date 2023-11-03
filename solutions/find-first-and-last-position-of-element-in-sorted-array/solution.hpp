#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> searchRange(const std::vector<int> &nums,
                                      int target) {
    auto range = std::equal_range(nums.begin(), nums.end(), target);
    if (range.first == nums.end() || *range.first != target) {
      return {-1, -1};
    }
    return {
        static_cast<int>(std::distance(nums.begin(), range.first)),
        static_cast<int>(std::distance(nums.begin(), std::prev(range.second)))};
  }
};