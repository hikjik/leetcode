#pragma once

#include <vector>

/*
  1562. Find Latest Group of Size M
  https://leetcode.com/problems/find-latest-group-of-size-m/
  Difficulty: Medium
  Tags: Array, Binary Search, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int findLatestStep(const std::vector<int> &arr, int m) {
    const int n = arr.size();
    if (m == n) {
      return n;
    }

    std::vector<int> length(n + 2, 0);
    int step = -1;
    for (int i = 0; i < n; ++i) {
      const auto a = arr[i];
      const auto left = length[a - 1], right = length[a + 1];
      length[a - left] = length[a + right] = left + right + 1;
      if (left == m || right == m) {
        step = i;
      }
    }
    return step;
  }
};
