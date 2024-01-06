#pragma once

#include <bit>
#include <numeric>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minOperations(const std::vector<int> &nums, int k) {
    return std::popcount(
        k ^ std::accumulate(nums.begin(), nums.end(), 0u, std::bit_xor{}));
  }
};
