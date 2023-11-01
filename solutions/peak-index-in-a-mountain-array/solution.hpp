#pragma once

#include <vector>

/*
  852. Peak Index in a Mountain Array
  https://leetcode.com/problems/peak-index-in-a-mountain-array/
  Difficulty: Medium
  Tags: Array, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static int peakIndexInMountainArray(const std::vector<int> &arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      arr[middle] < arr[middle + 1] ? left = middle + 1 : right = middle;
    }
    return left;
  }
};
