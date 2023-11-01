#pragma once

#include <queue>
#include <string>
#include <tuple>
#include <vector>

/*
  864. Shortest Path to Get All Keys
  https://leetcode.com/problems/shortest-path-to-get-all-keys/
  Difficulty: Hard
  Tags: Array, Bit Manipulation, Breadth-First Search, Matrix
  Time:
  Space:
*/

class Solution {
private:
  static const char kWall = '#';
  static const char kStart = '@';

public:
  static int shortestPathAllKeys(const std::vector<std::string> &grid) {
    const int m = grid.size(), n = grid.back().size();
    const auto k = (1 << countKeys(grid)) - 1;
    const auto start = getStart(grid);

    std::vector visited(m, std::vector(n, std::vector<bool>(k)));
    visited[start[0]][start[1]][0] = true;

    std::queue<std::tuple<int, int, int>> queue;
    queue.emplace(start[0], start[1], 0);

    std::vector<std::pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int steps = 0;
    while (!queue.empty()) {
      ++steps;
      for (int sz = queue.size(); sz > 0; --sz) {
        const auto [i, j, state] = queue.front();
        queue.pop();

        for (const auto &[di, dj] : dirs) {
          const int r = i + di, c = j + dj;
          if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == kWall) {
            continue;
          }

          const auto key = isKey(grid[r][c]) ? 1 << (grid[r][c] - 'a') : 0;
          const auto new_state = state | key;
          if (new_state == k) {
            return steps;
          }

          if (visited[r][c][new_state]) {
            continue;
          }

          const auto lock = isLock(grid[r][c]) ? 1 << (grid[r][c] - 'A') : 0;
          if (lock && !(new_state & lock)) {
            continue;
          }

          visited[r][c][new_state] = true;
          queue.emplace(r, c, new_state);
        }
      }
    }

    return -1;
  }

private:
  static bool isKey(char c) { return 'a' <= c && c <= 'f'; }

  static bool isLock(char c) { return 'A' <= c && c <= 'F'; }

  static int countKeys(const std::vector<std::string> &grid) {
    int cnt = 0;
    for (const auto &row : grid) {
      for (auto c : row) {
        if (isKey(c)) {
          ++cnt;
        }
      }
    }
    return cnt;
  }

  static std::vector<int> getStart(const std::vector<std::string> &grid) {
    const int m = grid.size(), n = grid.back().size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == kStart) {
          return {i, j};
        }
      }
    }
    throw;
  }
};
