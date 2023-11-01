#pragma once

#include <vector>

/*
  2425. Bitwise XOR of All Pairings
  https://leetcode.com/problems/bitwise-xor-of-all-pairings/
  Difficulty: Medium
  Tags: Array, Bit Manipulation, Brainteaser
  Time:
  Space:
*/

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
