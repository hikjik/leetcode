#pragma once

#include <algorithm>
#include <vector>

/*
  658. Find K Closest Elements
  https://leetcode.com/problems/find-k-closest-elements/
  Difficulty: Medium
  Tags: Array, Two Pointers, Binary Search, Sliding Window, Sorting,
        Heap (Priority Queue)
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> findClosestElements(const std::vector<int> &arr,
                                              int k, int x) {
    int left = 0, right = arr.size() - k;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      if (x - arr[middle] <= arr[middle + k] - x) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return {arr.begin() + left, arr.begin() + left + k};
  }
};
