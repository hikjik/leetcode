#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool isToeplitzMatrix(const std::vector<std::vector<int>> &matrix) {
    const int m = matrix.size(), n = matrix.back().size();
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] != matrix[i - 1][j - 1]) {
          return false;
        }
      }
    }
    return true;
  }
};
