#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int longestSubarray(const std::vector<int> &nums) {
    const int n = nums.size();

    int ans = 0;
    int zeros = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      zeros += !nums[r];
      while (zeros > 1) {
        zeros -= !nums[l++];
      }
      ans = std::max(ans, r - l + 1 - zeros);
    }
    return std::min(ans, n - 1);
  }
};
