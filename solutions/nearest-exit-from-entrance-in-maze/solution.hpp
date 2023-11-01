#pragma once

#include <queue>
#include <vector>

/*
  1926. Nearest Exit from Entrance in Maze
  https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
  Difficulty: Medium
  Tags: Array, Breadth-First Search, Matrix
  Time:
  Space:
*/

class Solution {
  static const char EMPTY = '.';
  static const char Wall = '+';

public:
  static int nearestExit(const std::vector<std::vector<char>> &maze,
                         const std::vector<int> &entrance) {
    int m = maze.size();
    int n = maze.back().size();

    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    std::vector<std::pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    std::queue<std::tuple<int, int, int>> queue;
    const auto i = entrance[0], j = entrance[1];
    visited[i][j] = true;
    queue.emplace(i, j, 0);

    while (!queue.empty()) {
      const auto [i, j, steps] = queue.front();
      queue.pop();

      for (const auto &[di, dj] : directions) {
        int r = i + di, c = j + dj;
        if (0 <= r && r < m && 0 <= c && c < n) {
          if (!visited[r][c] && maze[r][c] == EMPTY) {
            visited[r][c] = true;
            queue.emplace(r, c, steps + 1);
          }
        } else {
          if (i != entrance[0] || j != entrance[1]) {
            return steps;
          }
        }
      }
    }

    return -1;
  }
};
