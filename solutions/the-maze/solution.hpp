#pragma once

#include <queue>
#include <vector>

// Time: O(MN(M+N))
// Space: O(MN)

class Solution {
public:
  static bool hasPath(const std::vector<std::vector<int>> &maze,
                      const std::vector<int> &start,
                      const std::vector<int> &destination) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int m = maze.size(), n = maze.back().size();

    std::vector visited(m, std::vector<bool>(n));
    visited[start[0]][start[1]] = true;

    std::queue<std::pair<int, int>> queue{{{start[0], start[1]}}};
    while (!queue.empty()) {
      const auto [i, j] = queue.front();
      queue.pop();

      for (const auto &[di, dj] : kDirs) {
        int r = i, c = j;
        for (r += di, c += dj;
             r >= 0 && r < m && c >= 0 && c < n && !maze[r][c];
             r += di, c += dj) {
        }
        r -= di, c -= dj;
        if (r == destination[0] && c == destination[1]) {
          return true;
        }
        if (!visited[r][c]) {
          visited[r][c] = true;
          queue.push({r, c});
        }
      }
    }
    return false;
  }
};
