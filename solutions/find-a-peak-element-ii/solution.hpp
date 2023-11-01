#pragma once

#include <algorithm>
#include <vector>

/*
  1901. Find a Peak Element II
  https://leetcode.com/problems/find-a-peak-element-ii/
  Difficulty: Medium
  Tags: Array, Binary Search, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int>
  findPeakGrid(const std::vector<std::vector<int>> &mat) {
    int left = 0, right = mat.size() - 1;
    while (left < right) {
      const auto middle = left + (right - left) / 2;

      if (*std::max_element(mat[middle].begin(), mat[middle].end()) <
          *std::max_element(mat[middle + 1].begin(), mat[middle + 1].end())) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }

    const int row = left;
    auto it = std::max_element(mat[row].begin(), mat[row].end());
    const int col = std::distance(mat[row].begin(), it);
    return {row, col};
  }
};
