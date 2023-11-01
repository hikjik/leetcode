#pragma once

#include <algorithm>
#include <vector>

/*
  2605. Form Smallest Number From Two Digit Arrays
  https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/
  Difficulty: Easy
  Tags: Array, Hash Table, Enumeration
  Time:
  Space:
*/

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
