#pragma once

#include <vector>

class Solution {
public:
  static void setZeroes(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size(), n = matrix.back().size();

    bool unset_first_row = false;
    for (int j = 0; j < n; ++j) {
      if (!matrix[0][j]) {
        unset_first_row = true;
      }
    }

    bool unset_first_col = false;
    for (int i = 0; i < m; ++i) {
      if (!matrix[i][0]) {
        unset_first_col = true;
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (!matrix[i][j]) {
          matrix[i][0] = matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (!matrix[i][0] || !matrix[0][j]) {
          matrix[i][j] = 0;
        }
      }
    }

    if (unset_first_row) {
      for (int j = 0; j < n; ++j) {
        matrix[0][j] = 0;
      }
    }

    if (unset_first_col) {
      for (int i = 0; i < m; ++i) {
        matrix[i][0] = 0;
      }
    }
  }
};
