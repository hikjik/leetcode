#pragma once

#include <vector>

/*
  1493. Longest Subarray of 1's After Deleting One Element
  https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
  Difficulty: Medium
  Tags: Array, Dynamic Programming, Sliding Window
  Time:
  Space:
*/

class Solution {
public:
  static int longestSubarray(const std::vector<int> &nums) {
    const int n = nums.size();
    int max_length = 0;
    int zeros = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      if (!nums[r]) {
        ++zeros;
      }
      while (zeros > 1) {
        if (!nums[l++]) {
          --zeros;
        }
      }
      max_length = std::max(max_length, r - l);
    }
    return max_length;
  }
};
