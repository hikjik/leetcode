#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minTaps(int n, const std::vector<int> &ranges) {
    std::vector<int> nums(n + 1);
    for (int i = 0; i <= n; ++i) {
      const auto left = std::max(0, i - ranges[i]);
      const auto right = std::min(n, i + ranges[i]);
      nums[left] = std::max(nums[left], right - left);
    }

    // 45. Jump Game II
    int taps = 0;
    int max_reach = 0, cur_reach = 0;
    for (int i = 0; i < n; ++i) {
      max_reach = std::max(max_reach, i + nums[i]);
      if (cur_reach == i) {
        ++taps;
        cur_reach = max_reach;
      }
    }

    return cur_reach == n ? taps : -1;
  }
};
