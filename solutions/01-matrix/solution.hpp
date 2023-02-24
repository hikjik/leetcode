#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  updateMatrix(const std::vector<std::vector<int>> &mat) {
    int n = mat.size();
    int m = mat.back().size();

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    std::vector<std::vector<int>> distances(n, std::vector<int>(m, 0));

    std::vector<std::pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    std::queue<std::tuple<int, int, int>> queue;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 0) {
          visited[i][j] = true;
          queue.emplace(i, j, 0);
        }
      }
    }

    while (!queue.empty()) {
      const auto [i, j, distance] = queue.front();
      queue.pop();
      distances[i][j] = distance;

      for (auto direction : directions) {
        int r = i + direction.first, c = j + direction.second;
        if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]) {
          visited[r][c] = true;
          queue.emplace(r, c, distance + 1);
        }
      }
    }

    return distances;
  }
};
