#pragma once

#include <bit>
#include <numeric>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minOperations(const std::vector<int> &nums) {
    const unsigned max = std::ranges::max(nums);
    return (max ? std::bit_width(max) - 1 : 0) +
           accumulate(nums.begin(), nums.end(), 0,
                      [](int a, unsigned b) { return a + std::popcount(b); });
  }
};
