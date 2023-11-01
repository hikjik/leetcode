#pragma once

#include <vector>

/*
  2760. Longest Even Odd Subarray With Threshold
  https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/
  Difficulty: Easy
  Tags: Array, Sliding Window
  Time:
  Space:
*/

class Solution {
public:
  static int longestAlternatingSubarray(const std::vector<int> &nums,
                                        int threshold) {
    int max_length = 0, length = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] > threshold) {
        length = 0;
      } else if (length && nums[i] % 2 != nums[i - 1] % 2) {
        ++length;
      } else {
        length = nums[i] % 2 == 0;
      }
      max_length = std::max(max_length, length);
    }
    return max_length;
  }
};
