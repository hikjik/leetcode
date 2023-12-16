#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int maximumBeauty(std::vector<int> nums, int k) {
    std::ranges::sort(nums);
    int ans = 0;
    for (int l = 0, r = 0; r < std::ssize(nums); ++r) {
      while (nums[r] - nums[l] > 2 * k) {
        ++l;
      }
      ans = std::max(ans, r - l + 1);
    }
    return ans;
  }
};
