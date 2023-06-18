#pragma once

#include <vector>

class Solution {
public:
  static int countPaths(const std::vector<std::vector<int>> &grid) {
    const int m = grid.size(), n = grid.back().size();

    std::vector dp(m, std::vector<int>(n, -1));
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cnt = (countPaths(i, j, grid, &dp) + cnt) % kMod;
      }
    }
    return cnt;
  }

private:
  static const int kMod = 1e9 + 7;

  static int countPaths(int i, int j, const std::vector<std::vector<int>> &grid,
                        std::vector<std::vector<int>> *dp) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    const int m = grid.size(), n = grid.back().size();

    auto &cnt = (*dp)[i][j];
    if (cnt != -1) {
      return cnt;
    }

    cnt = 1;
    for (auto [di, dj] : kDirs) {
      int r = i + di, c = j + dj;
      if (0 <= r && r < m && 0 <= c && c < n && grid[i][j] < grid[r][c]) {
        cnt = (countPaths(r, c, grid, dp) + cnt) % kMod;
      }
    }

    return cnt;
  }
};
