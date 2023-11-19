#pragma once

#include <ranges>
#include <vector>

// Time: O(NLogN)
// Space: O(N)

class Solution {
public:
  static int reductionOperations(std::vector<int> nums) {
    std::ranges::sort(nums);

    int ans = 0;
    for (int up = 0, i = 1; i < std::ssize(nums); ++i) {
      ans += up += nums[i] > nums[i - 1];
    }
    return ans;
  }
};
