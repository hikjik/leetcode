#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int islandPerimeter(const std::vector<std::vector<int>> &grid) {
    const int n = grid.size(), m = grid.back().size();

    int perimeter = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j]) {
          perimeter += 4;
          if (i && grid[i - 1][j]) {
            perimeter -= 2;
          }
          if (j && grid[i][j - 1]) {
            perimeter -= 2;
          }
        }
      }
    }
    return perimeter;
  }
};
