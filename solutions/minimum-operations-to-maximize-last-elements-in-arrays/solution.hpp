#pragma once

#include <ranges>
#include <vector>

// Time:  O(N)
// Space: O(1)

class Solution {
public:
  static int minOperations(const std::vector<int> &nums1,
                           const std::vector<int> &nums2) {
    const auto [min, max] = std::ranges::minmax(nums1.back(), nums2.back());
    int ops1 = 0, ops2 = 0;
    for (int i = 0; i < std::ssize(nums1); ++i) {
      if (std::min(nums1[i], nums2[i]) > min ||
          std::max(nums1[i], nums2[i]) > max) {
        return -1;
      }
      ops1 += nums1[i] > nums1.back() || nums2[i] > nums2.back();
      ops2 += nums1[i] > nums2.back() || nums2[i] > nums1.back();
    }
    return std::min(ops1, ops2);
  }
};
