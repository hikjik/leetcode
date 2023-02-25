#pragma once

#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  pacificAtlantic(const std::vector<std::vector<int>> &heights) {
    int n = heights.size();
    int m = heights.back().size();

    std::vector<std::vector<bool>> pacific(n, std::vector<bool>(m, false));
    std::vector<std::vector<bool>> atlantic(n, std::vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
      dfs(i, 0, heights, &pacific);
      dfs(i, m - 1, heights, &atlantic);
    }
    for (int j = 0; j < m; ++j) {
      dfs(0, j, heights, &pacific);
      dfs(n - 1, j, heights, &atlantic);
    }

    std::vector<std::vector<int>> coords;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (pacific[i][j] && atlantic[i][j]) {
          coords.push_back({i, j});
        }
      }
    }
    return coords;
  }

private:
  static void dfs(int i, int j, const std::vector<std::vector<int>> &heights,
                  std::vector<std::vector<bool>> *visited) {
    static std::vector<std::pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    int n = heights.size();
    int m = heights.back().size();

    (*visited)[i][j] = true;

    for (auto direction : directions) {
      int r = i + direction.first, c = j + direction.second;
      if (r >= 0 && r < n && c >= 0 && c < m && !(*visited)[r][c] &&
          heights[i][j] <= heights[r][c]) {
        dfs(r, c, heights, visited);
      }
    }
  }
};
