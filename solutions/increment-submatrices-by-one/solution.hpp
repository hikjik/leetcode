#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>>
  rangeAddQueries(int n, const std::vector<std::vector<int>> &queries) {
    std::vector<std::vector<int>> mat(n, std::vector<int>(n, 0));
    for (const auto &q : queries) {
      int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
      ++mat[x1][y1];
      if (x2 + 1 < n && y2 + 1 < n) {
        ++mat[x2 + 1][y2 + 1];
      }
      if (x2 + 1 < n) {
        --mat[x2 + 1][y1];
      }
      if (y2 + 1 < n) {
        --mat[x1][y2 + 1];
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j + 1 < n; ++j) {
        mat[i][j + 1] += mat[i][j];
      }
    }
    for (int i = 0; i + 1 < n; ++i) {
      for (int j = 0; j < n; ++j) {
        mat[i + 1][j] += mat[i][j];
      }
    }
    return mat;
  }
};
