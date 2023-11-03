#pragma once

#include <algorithm>
#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static const char LAND = 0;
  static const char WATER = 1;

  static int closedIsland(const std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    int m = grid.back().size();

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    std::vector<std::pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    int closed_island_count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!visited[i][j] && grid[i][j] == LAND) {
          bool is_closed = true;
          std::queue<std::pair<int, int>> queue;

          visited[i][j] = true;
          queue.emplace(i, j);

          while (!queue.empty()) {
            const auto item = queue.front();
            queue.pop();

            for (auto direction : directions) {
              int r = item.first + direction.first;
              int c = item.second + direction.second;
              if (r >= 0 && r < n && c >= 0 && c < m) {
                if (!visited[r][c] && grid[r][c] == LAND) {
                  visited[r][c] = true;
                  queue.emplace(r, c);
                }
              } else {
                is_closed = false;
              }
            }
          }
          closed_island_count += is_closed;
        }
      }
    }

    return closed_island_count;
  }
};
