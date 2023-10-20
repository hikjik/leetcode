#pragma once

#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  construct2DArray(const std::vector<int> &original, int m, int n) {
    if (m * n != std::ssize(original)) {
      return {};
    }
    std::vector matrix(m, std::vector<int>(n));
    for (int i = 0, k = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        matrix[i][j] = original[k++];
      }
    }
    return matrix;
  }
};
