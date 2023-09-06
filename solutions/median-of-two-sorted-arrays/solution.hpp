#pragma once

#include <climits>
#include <vector>

class Solution {
public:
  static double findMedianSortedArrays(const std::vector<int> &nums1,
                                       const std::vector<int> &nums2) {
    const int n1 = nums1.size(), n2 = nums2.size();
    if (n1 > n2) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int left = 0, right = n1;
    while (left <= right) {
      const auto l1 = left + (right - left) / 2;
      const auto l2 = (n1 + n2 + 1) / 2 - l1;

      const auto f1 = l1 ? nums1[l1 - 1] : INT_MIN;
      const auto f2 = l1 < n1 ? nums1[l1] : INT_MAX;

      const auto s1 = l2 ? nums2[l2 - 1] : INT_MIN;
      const auto s2 = l2 < n2 ? nums2[l2] : INT_MAX;

      if (f1 > s2) {
        right = l1 - 1;
      } else if (f2 < s1) {
        left = l1 + 1;
      } else {
        if ((n1 + n2) % 2 == 0) {
          return (std::max(f1, s1) + std::min(f2, s2)) * 0.5;
        } else {
          return std::max(f1, s1);
        }
      }
    }

    throw;
  }
};
