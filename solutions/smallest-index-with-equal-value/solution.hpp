#pragma once

#include <vector>

/*
  2057. Smallest Index With Equal Value
  https://leetcode.com/problems/smallest-index-with-equal-value/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static int smallestEqual(const std::vector<int> &nums) {
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (i % 10 == nums[i]) {
        return i;
      }
    }
    return -1;
  }
};
