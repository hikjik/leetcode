#pragma once

#include <climits>
#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int findValueOfPartition(std::vector<int> nums) {
    std::ranges::sort(nums);

    int ans = INT_MAX;
    for (int i = 1; i < std::ssize(nums); ++i) {
      ans = std::min(ans, nums[i] - nums[i - 1]);
    }
    return ans;
  }
};
