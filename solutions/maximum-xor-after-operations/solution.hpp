#pragma once

#include <numeric>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int maximumXOR(const std::vector<int> &nums) {
    return std::accumulate(nums.begin(), nums.end(), 0, std::bit_or{});
  }
};
