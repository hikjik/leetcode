#pragma once

#include <vector>

/*
  2540. Minimum Common Value
  https://leetcode.com/problems/minimum-common-value/
  Difficulty: Easy
  Tags: Array, Hash Table, Two Pointers, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static int getCommon(const std::vector<int> &nums1,
                       const std::vector<int> &nums2) {

    for (size_t i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
      if (nums1[i] == nums2[j]) {
        return nums1[i];
      }
      nums1[i] < nums2[j] ? ++i : ++j;
    }
    return -1;
  }
};
