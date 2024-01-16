#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> largestSubarray(const std::vector<int> &nums, int k) {
    const auto it = std::max_element(nums.cbegin(), nums.cend() - k + 1);
    return {it, it + k};
  }
};
