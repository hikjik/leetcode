#pragma once

#include <algorithm>
#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static const char LAND = 1;
  static const char WATER = 0;

  static int maxAreaOfIsland(const std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    int m = grid.back().size();

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    std::vector<std::pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    int max_area = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int area = 0;
        if (!visited[i][j] && grid[i][j] == LAND) {
          std::queue<std::pair<int, int>> queue;

          area++;
          visited[i][j] = true;
          queue.emplace(i, j);

          while (!queue.empty()) {
            const auto item = queue.front();
            queue.pop();

            for (auto direction : directions) {
              int r = item.first + direction.first;
              int c = item.second + direction.second;
              if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c] &&
                  grid[r][c] == LAND) {
                area++;
                visited[r][c] = true;
                queue.emplace(r, c);
              }
            }
          }
        }
        max_area = std::max(max_area, area);
      }
    }

    return max_area;
  }
};
