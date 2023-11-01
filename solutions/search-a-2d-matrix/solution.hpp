#pragma once

#include <vector>

template <typename T> using Matrix = std::vector<std::vector<T>>;

/*
  74. Search a 2D Matrix
  https://leetcode.com/problems/search-a-2d-matrix/
  Difficulty: Medium
  Tags: Array, Binary Search, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static bool searchMatrix(const Matrix<int> &matrix, int target) {
    const int rows = matrix.size(), cols = matrix.back().size();

    auto left = 0, right = rows * cols;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      const auto element = matrix[middle / cols][middle % cols];

      if (element == target) {
        return true;
      } else if (element < target) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }

    return false;
  }
};
