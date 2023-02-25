#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static int
  shortestPathBinaryMatrix(const std::vector<std::vector<int>> &grid) {
    int n = grid.size();

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    std::queue<std::tuple<int, int, int>> queue;
    if (grid[0][0] == 0) {
      visited[0][0] = true;
      queue.emplace(0, 0, 1);
    }

    std::vector<std::pair<int, int>> directions{
        {-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    while (!queue.empty()) {
      const auto [i, j, path_length] = queue.front();
      queue.pop();

      if (i == n - 1 && j == n - 1) {
        return path_length;
      }

      for (const auto &[di, dj] : directions) {
        int r = i + di, c = j + dj;
        if (0 <= r && r < n && 0 <= c && c < n && !visited[r][c] &&
            grid[r][c] == 0) {
          visited[r][c] = true;
          queue.emplace(r, c, path_length + 1);
        }
      }
    }

    return -1;
  }
};
