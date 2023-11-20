#pragma once

#include <cmath>
#include <numeric>
#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int minMoves2(std::vector<int> nums) {
    std::ranges::nth_element(nums, nums.begin() + nums.size() / 2);
    const auto median = nums[nums.size() / 2];
    return std::accumulate(nums.begin(), nums.end(), 0, [=](int a, int b) {
      return a + std::abs(b - median);
    });
  }
};
