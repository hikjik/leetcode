#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static const int LAND = 1;
  static const int WATER = 0;

  static int numEnclaves(const std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    int m = grid.back().size();

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    int enclaves_count = 0;
    std::vector<std::pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!visited[i][j] && grid[i][j] == LAND) {
          std::queue<std::pair<int, int>> queue;
          bool is_enclave = true;
          int cells_count = 1;

          visited[i][j] = true;
          queue.emplace(i, j);

          while (!queue.empty()) {
            const auto item = queue.front();
            queue.pop();

            for (auto direction : directions) {
              int r = item.first + direction.first;
              int c = item.second + direction.second;
              if (r >= 0 && r < n && c >= 0 && c < m) {
                if (!visited[r][c] && grid[r][c] == LAND) {
                  visited[r][c] = true;
                  queue.emplace(r, c);
                  cells_count++;
                }
              } else {
                is_enclave = false;
              }
            }
          }
          enclaves_count += is_enclave ? cells_count : 0;
        }
      }
    }

    return enclaves_count;
  }
};
