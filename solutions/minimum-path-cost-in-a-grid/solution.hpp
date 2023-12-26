#pragma once

#include <climits>
#include <ranges>
#include <vector>

// Time: O(MN^2)
// Space: O(MN)

class Solution {
public:
  static int minPathCost(std::vector<std::vector<int>> grid,
                         const std::vector<std::vector<int>> &moveCost) {
    const int m = grid.size(), n = grid.back().size();
    for (int i = m - 2; i >= 0; --i) {
      for (int j = 0; j < n; ++j) {
        int cost = INT_MAX;
        for (int k = 0; k < n; ++k) {
          cost = std::min(cost, grid[i + 1][k] + moveCost[grid[i][j]][k]);
        }
        grid[i][j] += cost;
      }
    }
    return std::ranges::min(grid[0]);
  }
};
