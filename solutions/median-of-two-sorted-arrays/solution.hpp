#pragma once

#include <climits>
#include <vector>

/*
  4. Median of Two Sorted Arrays
  https://leetcode.com/problems/median-of-two-sorted-arrays/
  Difficulty: Hard
  Tags: Array, Binary Search, Divide and Conquer
  Time:
  Space:
*/

class Solution {
public:
  static double findMedianSortedArrays(const std::vector<int> &nums1,
                                       const std::vector<int> &nums2) {
    const int n = nums1.size(), m = nums2.size();
    if (n > m) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int left = 0, right = n;
    while (left <= right) {
      const auto l1 = left + (right - left) / 2;
      const auto l2 = (n + m + 1) / 2 - l1;

      const auto f1 = l1 ? nums1[l1 - 1] : INT_MIN;
      const auto f2 = l1 < n ? nums1[l1] : INT_MAX;

      const auto s1 = l2 ? nums2[l2 - 1] : INT_MIN;
      const auto s2 = l2 < m ? nums2[l2] : INT_MAX;

      if (f1 > s2) {
        right = l1 - 1;
      } else if (f2 < s1) {
        left = l1 + 1;
      } else {
        if ((n + m) % 2 == 0) {
          return (std::max(f1, s1) + std::min(f2, s2)) * 0.5;
        } else {
          return std::max(f1, s1);
        }
      }
    }

    throw;
  }
};
