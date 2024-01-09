#pragma once

#include <climits>
#include <queue>
#include <vector>

// Time: O(MN)
// Space: O(MN)

class Solution {
public:
  static void wallsAndGates(std::vector<std::vector<int>> &rooms) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int m = rooms.size(), n = rooms.back().size();

    std::queue<std::pair<int, int>> queue;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!rooms[i][j]) {
          queue.push({i, j});
        }
      }
    }

    while (!queue.empty()) {
      const auto [i, j] = queue.front();
      queue.pop();

      for (const auto &[di, dj] : kDirs) {
        const int r = i + di, c = j + dj;
        if (0 <= r && r < m && 0 <= c && c < n && rooms[r][c] == INT_MAX) {
          rooms[r][c] = rooms[i][j] + 1;
          queue.push({r, c});
        }
      }
    }
  }
};
