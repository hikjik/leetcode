#pragma once

#include <vector>

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
