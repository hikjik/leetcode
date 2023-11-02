#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
  static const int EMPTY = 0;
  static const int FRESH = 1;
  static const int ROTTEN = 2;

public:
  static int orangesRotting(const std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    int m = grid.back().size();

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    std::vector<std::pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    std::queue<std::tuple<int, int, int>> queue;
    int fresh_count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == ROTTEN) {
          visited[i][j] = true;
          queue.emplace(i, j, 0);
        }
        if (grid[i][j] == FRESH) {
          fresh_count++;
        }
      }
    }

    int min_minutes = 0;
    while (!queue.empty()) {
      const auto [i, j, minutes] = queue.front();
      queue.pop();

      min_minutes = std::max(min_minutes, minutes);

      for (auto direction : directions) {
        int r = i + direction.first, c = j + direction.second;
        if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c] &&
            grid[r][c] == FRESH) {
          visited[r][c] = true;
          fresh_count--;
          queue.emplace(r, c, minutes + 1);
        }
      }
    }

    return fresh_count ? -1 : min_minutes;
  }
};
