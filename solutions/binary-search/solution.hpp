#pragma once

#include <vector>

/*
  704. Binary Search
  https://leetcode.com/problems/binary-search/
  Difficulty: Easy
  Tags: Array, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static int search(const std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] == target) {
        return middle;
      }

      if (nums[middle] > target) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return -1;
  }
};