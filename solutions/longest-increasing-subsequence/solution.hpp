#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int lengthOfLIS(const std::vector<int> &nums) {
    std::vector<int> dp;
    for (auto a : nums) {
      auto it = std::lower_bound(dp.begin(), dp.end(), a);
      if (it == dp.end()) {
        dp.push_back(a);
      } else {
        *it = a;
      }
    }
    return dp.size();
  }
};
