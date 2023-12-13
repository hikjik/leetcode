#pragma once

#include <numeric>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int xorBeauty(const std::vector<int> &nums) {
    return std::reduce(nums.begin(), nums.end(), 0, std::bit_xor{});
  }
};
