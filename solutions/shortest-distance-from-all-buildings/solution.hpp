#pragma once

#include <climits>
#include <queue>
#include <tuple>
#include <vector>

// Time: O(M^2N^2)
// Space: O(MN)

class Solution {
public:
  static int shortestDistance(std::vector<std::vector<int>> grid) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int m = grid.size(), n = grid.back().size();

    std::vector dist(m, std::vector<int>(n));

    int ans = INT_MAX;
    int land = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != 1) {
          continue;
        }
        ans = INT_MAX;
        std::queue<std::pair<int, int>> queue{{{i, j}}};
        for (int steps = 0; !queue.empty(); ++steps) {
          for (int sz = queue.size(); sz; --sz) {
            const auto [x, y] = queue.front();
            queue.pop();

            for (const auto &[dx, dy] : kDirs) {
              const int r = x + dx, c = y + dy;
              if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != land) {
                continue;
              }
              --grid[r][c];
              dist[r][c] += steps + 1;
              ans = std::min(ans, dist[r][c]);
              queue.push({r, c});
            }
          }
        }
        --land;
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
