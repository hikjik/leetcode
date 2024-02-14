#pragma once

#include <vector>

// Time: O(NM)
// Space: O(NM)

class Solution {
public:
  static std::vector<std::vector<int>>
  modifiedMatrix(std::vector<std::vector<int>> matrix) {
    const int n = matrix.size(), m = matrix.back().size();
    for (int j = 0; j < m; ++j) {
      auto max = -1;
      for (int i = 0; i < n; ++i) {
        max = std::max(max, matrix[i][j]);
      }
      for (int i = 0; i < n; ++i) {
        if (matrix[i][j] == -1) {
          matrix[i][j] = max;
        }
      }
    }
    return matrix;
  }
};
