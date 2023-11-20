#pragma once

#include <numeric>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minMoves(const std::vector<int> &nums) {
    return std::reduce(nums.begin(), nums.end(), 0LL) -
           std::ranges::min(nums) * nums.size();
  }
};
