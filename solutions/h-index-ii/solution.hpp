#pragma once

#include <vector>

/*
  275. H-Index II
  https://leetcode.com/problems/h-index-ii/
  Difficulty: Medium
  Tags: Array, Binary Search
  Time:
  Space:
*/

class Solution {
public:
  static int hIndex(const std::vector<int> &citations) {
    int n = citations.size();
    int left = 0, right = n;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      if (citations[middle] >= n - middle) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return n - left;
  }
};
