#pragma once

#include <algorithm>
#include <vector>

/*
  1004. Max Consecutive Ones III
  https://leetcode.com/problems/max-consecutive-ones-iii/
  Difficulty: Medium
  Tags: Array, Binary Search, Sliding Window, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static int longestOnes(const std::vector<int> &nums, int k) {
    int max_length = 0;
    int ones = 0, zeros = 0;
    for (size_t l = 0, r = 0; r < nums.size(); ++r) {
      nums[r] ? ++ones : ++zeros;
      while (zeros > k) {
        nums[l++] ? --ones : --zeros;
      }
      max_length = std::max(max_length, ones + zeros);
    }
    return max_length;
  }
};
