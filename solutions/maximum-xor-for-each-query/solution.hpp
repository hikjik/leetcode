#pragma once

#include <numeric>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> getMaximumXor(const std::vector<int> &nums,
                                        int maximumBit) {
    std::vector<int> ans(nums.size());
    std::inclusive_scan(nums.cbegin(), nums.cend(), ans.rbegin(),
                        std::bit_xor{}, (1 << maximumBit) - 1);
    return ans;
  }
};
