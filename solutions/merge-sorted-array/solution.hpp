#pragma once

#include <vector>

class Solution {
public:
  static void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2,
                    int n) {
    int i = m - 1;
    int j = n - 1;
    int k = n + m - 1;
    while (k >= 0) {
      if (j < 0 || (i >= 0 && nums1[i] > nums2[j])) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
  }
};