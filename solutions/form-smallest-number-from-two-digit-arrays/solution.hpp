#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minNumber(const std::vector<int> &nums1,
                       const std::vector<int> &nums2) {
    int ans = 89;
    for (auto a : nums1) {
      for (auto b : nums2) {
        ans = std::min(ans, a == b ? a : std::min(a, b) * 10 + std::max(a, b));
      }
    }
    return ans;
  }
};
