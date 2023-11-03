#pragma once

#include <vector>

// Time: O(N^2)
// Space: O(1)

class Solution {
public:
  static void rotate(std::vector<std::vector<int>> &matrix) {
    std::reverse(matrix.begin(), matrix.end());
    transpose(matrix);
  }

private:
  static void transpose(std::vector<std::vector<int>> &matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
      for (size_t j = i + 1; j < matrix.size(); ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};
