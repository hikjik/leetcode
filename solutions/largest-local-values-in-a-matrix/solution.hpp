#pragma once

#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  largestLocal(const std::vector<std::vector<int>> &grid) {
    const int n = grid.size();

    std::vector mat(n - 2, std::vector<int>(n - 2));
    for (int i = 0; i < n - 2; ++i) {
      for (int j = 0; j < n - 2; ++j) {
        for (int x = i; x <= i + 2; ++x) {
          for (int y = j; y <= j + 2; ++y) {
            mat[i][j] = std::max(mat[i][j], grid[x][y]);
          }
        }
      }
    }
    return mat;
  }
};
