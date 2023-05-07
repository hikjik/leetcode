#pragma once

#include <algorithm>
#include <vector>

class Solution {
private:
  template <typename T> using Array2D = std::vector<std::vector<T>>;
  template <typename T> using Array3D = std::vector<Array2D<T>>;

  static int dfs(int x1, int y1, int x2, const Array2D<int> &grid,
                 Array3D<int> *dp) {
    const int n = grid.size();
    const auto y2 = x1 + y1 - x2;

    if (x1 == n || y1 == n || x2 == n || y2 == n) {
      return -1;
    }
    if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
      return -1;
    }
    if (x1 == n - 1 && y1 == n - 1) {
      return grid[x1][y1];
    }

    auto &cnt = (*dp)[x1][y1][x2];
    if (cnt != -2) {
      return cnt;
    }

    cnt = std::max({
        dfs(x1 + 1, y1, x2, grid, dp),
        dfs(x1 + 1, y1, x2 + 1, grid, dp),
        dfs(x1, y1 + 1, x2, grid, dp),
        dfs(x1, y1 + 1, x2 + 1, grid, dp),
    });

    if (cnt == -1) {
      return cnt;
    }

    return cnt += x1 == x2 ? grid[x1][y1] : grid[x1][y1] + grid[x2][y2];
  }

public:
  static int cherryPickup(const Array2D<int> &grid) {
    const int n = grid.size();
    Array3D<int> dp(n + 1, Array2D<int>(n + 1, std::vector<int>(n + 1, -2)));
    return std::max(0, dfs(0, 0, 0, grid, &dp));
  }
};
