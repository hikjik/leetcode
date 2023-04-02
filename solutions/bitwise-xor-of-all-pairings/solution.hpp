#pragma once

#include <vector>

class Solution {
public:
  static int xorAllNums(const std::vector<int> &nums1,
                        const std::vector<int> &nums2) {
    int sum = 0;
    if (nums2.size() % 2 == 1) {
      for (auto num : nums1) {
        sum ^= num;
      }
    }
    if (nums1.size() % 2 == 1) {
      for (auto num : nums2) {
        sum ^= num;
      }
    }
    return sum;
  }
};
