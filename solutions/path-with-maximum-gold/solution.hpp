#pragma once

#include <vector>

// K is the number of cell with gold
// Time: O(K3^K)
// Space: O(K)

class Solution {
public:
  static int getMaximumGold(std::vector<std::vector<int>> grid) {
    int ans = 0;
    for (int i = 0; i < std::ssize(grid); ++i) {
      for (int j = 0; j < std::ssize(grid[i]); ++j) {
        ans = std::max(ans, dfs(i, j, grid));
      }
    }
    return ans;
  }

private:
  static int dfs(int i, int j, std::vector<std::vector<int>> &grid) {
    if (i < 0 || i == std::ssize(grid) || j < 0 || j == std::ssize(grid[i])) {
      return 0;
    }
    if (!grid[i][j]) {
      return 0;
    }
    const auto cache = std::exchange(grid[i][j], 0);
    const auto path = std::max({
        dfs(i + 1, j, grid),
        dfs(i - 1, j, grid),
        dfs(i, j + 1, grid),
        dfs(i, j - 1, grid),
    });
    grid[i][j] = cache;
    return grid[i][j] + path;
  }
};
