#pragma once

#include <vector>

/*
  240. Search a 2D Matrix II
  https://leetcode.com/problems/search-a-2d-matrix-ii/
  Difficulty: Medium
  Tags: Array, Binary Search, Divide and Conquer, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static bool searchMatrix(const std::vector<std::vector<int>> &matrix,
                           int target) {
    int m = matrix.size(), n = matrix.back().size();
    int row = 0, col = n - 1;
    while (row < m && col >= 0) {
      if (matrix[row][col] == target) {
        return true;
      }
      if (matrix[row][col] > target) {
        --col;
      } else {
        ++row;
      }
    }
    return false;
  }
};
