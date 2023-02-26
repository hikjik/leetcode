#pragma once

#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

class Solution {
public:
  static int minimumTime(const std::vector<std::vector<int>> &grid) {
    if (grid[0][1] > 1 && grid[1][0] > 1) {
      return -1;
    }

    int n = grid.size(), m = grid.back().size();

    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>,
                        std::greater<std::tuple<int, int, int>>>
        queue;
    std::vector<std::vector<int>> times(
        n, std::vector<int>(m, std::numeric_limits<int>::max()));

    std::vector<std::pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    queue.push({0, 0, 0});
    times[0][0] = 0;
    while (!queue.empty()) {
      const auto [t, i, j] = queue.top();
      queue.pop();

      if (i == n - 1 && j == m - 1) {
        return t;
      }

      for (const auto &[di, dj] : directions) {
        int r = i + di, c = j + dj;
        if (r >= 0 && r < n && c >= 0 && c < m) {
          int diff = std::max(grid[r][c] - t, 0);
          if (diff & 1) {
            diff ^= 1;
          }
          int tt = diff + t + 1;
          if (times[r][c] > tt) {
            times[r][c] = tt;
            queue.push({tt, r, c});
          }
        }
      }
    }
    return -1;
  }
};
