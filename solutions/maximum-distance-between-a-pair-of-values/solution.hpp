#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxDistance(const std::vector<int> &nums1,
                         const std::vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();

    int max_distance = 0;
    for (int i = 0; i < n; ++i) {
      auto it = std::lower_bound(nums2.rbegin(), nums2.rend(), nums1[i]);
      const int j = m - std::distance(nums2.rbegin(), it) - 1;
      max_distance = std::max(max_distance, j - i);
    }
    return max_distance;
  }
};
