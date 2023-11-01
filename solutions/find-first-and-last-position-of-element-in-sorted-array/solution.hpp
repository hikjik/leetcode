#pragma once

#include <vector>

/*
  34. Find First and Last Position of Element in Sorted Array
  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
  Difficulty: Medium
  Tags: Array, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> searchRange(const std::vector<int> &nums,
                                      int target) {
    auto range = std::equal_range(nums.begin(), nums.end(), target);
    if (range.first == nums.end() || *range.first != target) {
      return {-1, -1};
    }
    return {
        static_cast<int>(std::distance(nums.begin(), range.first)),
        static_cast<int>(std::distance(nums.begin(), std::prev(range.second)))};
  }
};