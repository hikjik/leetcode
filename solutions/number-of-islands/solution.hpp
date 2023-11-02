#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static const char LAND = '1';
  static const char WATER = '0';

  static int numIslands(const std::vector<std::vector<char>> &grid) {
    int n = grid.size();
    int m = grid.back().size();

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    int islands_count = 0;
    std::vector<std::pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!visited[i][j] && grid[i][j] == LAND) {
          islands_count++;

          visited[i][j] = true;

          std::queue<std::pair<int, int>> queue;
          queue.emplace(i, j);
          while (!queue.empty()) {
            const auto item = queue.front();
            queue.pop();

            for (auto direction : directions) {
              int r = item.first + direction.first;
              int c = item.second + direction.second;
              if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c] &&
                  grid[r][c] == LAND) {
                visited[r][c] = true;
                queue.emplace(r, c);
              }
            }
          }
        }
      }
    }

    return islands_count;
  }
};