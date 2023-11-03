#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>>
  updateMatrix(const std::vector<std::vector<int>> &mat) {
    const int n = mat.size(), m = mat.back().size();

    static const std::vector<std::pair<int, int>> dirs{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    std::vector visited(n, std::vector<bool>(m));
    std::vector distances(n, std::vector<int>(m));
    std::queue<std::pair<int, int>> queue;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!mat[i][j]) {
          visited[i][j] = true;
          queue.emplace(i, j);
        }
      }
    }

    for (int distance = 0; !queue.empty(); ++distance) {
      for (int sz = queue.size(); sz; --sz) {
        const auto [i, j] = queue.front();
        queue.pop();

        distances[i][j] = distance;

        for (const auto &[di, dj] : dirs) {
          const auto r = i + di, c = j + dj;
          if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]) {
            visited[r][c] = true;
            queue.emplace(r, c);
          }
        }
      }
    }

    return distances;
  }
};
