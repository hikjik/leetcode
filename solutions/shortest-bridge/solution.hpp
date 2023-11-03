#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
private:
  static const int LAND = 1;
  static const int WATER = 0;

  static inline const std::vector<std::pair<int, int>> DIRECTION{
      {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

public:
  static int shortestBridge(const std::vector<std::vector<int>> &grid) {
    std::vector<std::pair<int, int>> island;
    findFirstIsland(grid, &island);

    int n = grid.size();
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

    std::queue<std::tuple<int, int, int>> queue;
    for (const auto &[i, j] : island) {
      queue.emplace(i, j, 0);
      visited[i][j] = true;
    }

    while (!queue.empty()) {
      const auto [i, j, steps] = queue.front();
      queue.pop();

      for (const auto &[di, dj] : DIRECTION) {
        int r = i + di, c = j + dj;
        if (r >= 0 && r < n && c >= 0 && c < n && !visited[r][c]) {
          if (grid[r][c] == LAND) {
            return steps;
          }
          visited[r][c] = true;
          queue.emplace(r, c, steps + 1);
        }
      }
    }

    return -1;
  }

private:
  static void findFirstIsland(const std::vector<std::vector<int>> &grid,
                              std::vector<std::pair<int, int>> *island) {
    int n = grid.size();

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == LAND && !visited[i][j]) {
          dfs(i, j, grid, &visited, island);
          return;
        }
      }
    }
  }

  static void dfs(int i, int j, const std::vector<std::vector<int>> &grid,
                  std::vector<std::vector<bool>> *visited,
                  std::vector<std::pair<int, int>> *island) {
    int n = grid.size();

    (*visited)[i][j] = true;
    island->emplace_back(i, j);

    for (const auto &[di, dj] : DIRECTION) {
      int r = i + di, c = j + dj;
      if (r >= 0 && r < n && c >= 0 && c < n && !(*visited)[r][c] &&
          grid[r][c] == LAND) {
        dfs(r, c, grid, visited, island);
      }
    }
  }
};
