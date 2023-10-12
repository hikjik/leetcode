#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static int maxDistance(const std::vector<std::vector<int>> &grid) {
    static const std::vector<std::pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    const int n = grid.size(), m = grid.back().size();

    std::vector visited(n, std::vector<bool>(m, false));

    std::queue<std::pair<int, int>> queue;
    bool no_water = true, no_land = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          no_land = false;
          visited[i][j] = true;
          queue.emplace(i, j);
        } else {
          no_water = false;
        }
      }
    }

    if (no_water || no_land) {
      return -1;
    }

    int max_distance = 0;
    for (int distance = 0; !queue.empty(); ++distance) {
      max_distance = std::max(max_distance, distance);

      for (int sz = queue.size(); sz; --sz) {
        const auto [i, j] = queue.front();
        queue.pop();

        for (auto direction : directions) {
          int r = i + direction.first, c = j + direction.second;
          if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]) {
            visited[r][c] = true;
            queue.emplace(r, c);
          }
        }
      }
    }

    return max_distance;
  }
};
