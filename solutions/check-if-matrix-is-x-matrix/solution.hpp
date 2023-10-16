#pragma once

#include <vector>

class Solution {
public:
  static bool checkXMatrix(const std::vector<std::vector<int>> &grid) {
    const int n = grid.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j || i == n - j - 1) {
          if (!grid[i][j]) {
            return false;
          }
        } else {
          if (grid[i][j]) {
            return false;
          }
        }
      }
    }
    return true;
  }
};
