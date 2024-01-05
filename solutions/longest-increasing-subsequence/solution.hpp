#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int lengthOfLIS(const std::vector<int> &nums) {
    std::vector<int> dp;
    for (auto num : nums) {
      if (auto it = std::ranges::lower_bound(dp, num); it == dp.end()) {
        dp.push_back(num);
      } else {
        *it = num;
      }
    }
    return dp.size();
  }
};
