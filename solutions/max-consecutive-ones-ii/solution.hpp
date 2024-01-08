#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int findMaxConsecutiveOnes(const std::vector<int> &nums) {
    int zeros = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < std::ssize(nums); ++r) {
      zeros += !nums[r];
      while (zeros > 1) {
        zeros -= !nums[l++];
      }
      ans = std::max(ans, r - l + 1);
    }
    return ans;
  }
};
