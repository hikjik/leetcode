#pragma once

#include <algorithm>
#include <vector>

/*
  1051. Height Checker
  https://leetcode.com/problems/height-checker/
  Difficulty: Easy
  Tags: Array, Sorting, Counting Sort
  Time:
  Space:
*/

class Solution {
public:
  static int heightChecker(const std::vector<int> &heights) {
    auto expected = heights;
    std::sort(expected.begin(), expected.end());

    int cnt = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
      cnt += heights[i] != expected[i];
    }
    return cnt;
  }
};
