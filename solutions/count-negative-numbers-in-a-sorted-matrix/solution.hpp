#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int countNegatives(const std::vector<std::vector<int>> &grid) {
    int n = grid.size(), m = grid.back().size();

    int j = m - 1;
    int negatives_count = 0;
    for (int i = 0; i < n; ++i) {
      while (j >= 0 && grid[i][j] < 0) {
        --j;
      }
      negatives_count += m - j - 1;
    }
    return negatives_count;
  }
};
