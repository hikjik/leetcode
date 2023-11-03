#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int uniquePathsIII(std::vector<std::vector<int>> grid) {
    int x = 0, y = 0;
    int empty = 1;
    for (size_t i = 0; i < grid.size(); ++i) {
      for (size_t j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == 0) {
          empty++;
        } else if (grid[i][j] == 1) {
          x = i, y = j;
        }
      }
    }

    int cnt = 0;
    dfs(x, y, empty, grid, &cnt);
    return cnt;
  }

private:
  static inline const std::vector<std::pair<int, int>> kDirs{
      {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  static void dfs(int i, int j, int empty, std::vector<std::vector<int>> &grid,
                  int *cnt) {
    int m = grid.size(), n = grid.back().size();
    if (i < 0 || i == m || j < 0 || j == n) {
      return;
    }
    if (grid[i][j] == -1) {
      return;
    }
    if (grid[i][j] == 2) {
      *cnt += !empty;
      return;
    }

    grid[i][j] = -1;
    for (const auto &[di, dj] : kDirs) {
      dfs(i + di, j + dj, empty - 1, grid, cnt);
    }
    grid[i][j] = 0;
  }
};
