#pragma once

#include <vector>

/*
  2765. Longest Alternating Subarray
  https://leetcode.com/problems/longest-alternating-subarray/
  Difficulty: Easy
  Tags: Array, Enumeration
  Time:
  Space:
*/

class Solution {
public:
  static int alternatingSubarray(const std::vector<int> &nums) {
    int max_length = -1, length = -1;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (length > 0 && nums[i] == nums[i - 2]) {
        ++length;
      } else if (nums[i] - nums[i - 1] == 1) {
        length = 2;
      } else {
        length = -1;
      }
      max_length = std::max(max_length, length);
    }
    return max_length;
  }
};
