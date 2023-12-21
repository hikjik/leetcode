#pragma once

#include <vector>

// Time: O(NM)
// Space: O(NM)

class Solution {
public:
  static int findMaxFish(std::vector<std::vector<int>> grid) {
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
    if (i < 0 || i >= std::ssize(grid) || j < 0 || j >= std::ssize(grid[i]) ||
        !grid[i][j]) {
      return 0;
    }
    return std::exchange(grid[i][j], 0) + dfs(i - 1, j, grid) +
           dfs(i + 1, j, grid) + dfs(i, j - 1, grid) + dfs(i, j + 1, grid);
  }
};
