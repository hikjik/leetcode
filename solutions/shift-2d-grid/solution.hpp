#pragma once

#include <ranges>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>>
  shiftGrid(const std::vector<std::vector<int>> &grid, int k) {
    const int rows = grid.size(), cols = grid.back().size();
    k %= rows * cols;

    std::vector ans(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        const int idx = (i * cols + j + k) % (rows * cols);
        ans[idx / cols][idx % cols] = grid[i][j];
      }
    }
    return ans;
  }
};
