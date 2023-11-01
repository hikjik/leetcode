#pragma once

#include <queue>
#include <vector>

/*
  130. Surrounded Regions
  https://leetcode.com/problems/surrounded-regions/
  Difficulty: Medium
  Tags: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static void solve(std::vector<std::vector<char>> &board) {
    int m = board.size(), n = board.back().size();
    std::vector<std::vector<char>> captured(m, std::vector<char>(n, 'X'));

    std::queue<std::pair<int, int>> queue;
    for (int i = 0; i < m; ++i) {
      for (int j : {0, n - 1}) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
          captured[i][j] = 'O';
          queue.emplace(i, j);
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      for (int i : {0, m - 1}) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
          captured[i][j] = 'O';
          queue.emplace(i, j);
        }
      }
    }

    std::vector<std::pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!queue.empty()) {
      auto [i, j] = queue.front();
      queue.pop();

      for (auto [di, dj] : dirs) {
        int r = i + di, c = j + dj;
        if (0 <= r && r < m && 0 <= c && c < n && board[r][c] == 'O') {
          board[r][c] = 'X';
          captured[r][c] = 'O';
          queue.emplace(r, c);
        }
      }
    }

    board.swap(captured);
  }
};
