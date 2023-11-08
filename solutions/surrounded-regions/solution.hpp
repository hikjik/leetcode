#pragma once

#include <queue>
#include <vector>

// Time: O(NM)
// Space: O(1)

namespace bfs {

// Time: O(NM)
// Space: O(1)
class Solution {
public:
  static void solve(std::vector<std::vector<char>> &board) {
    static std::vector<std::pair<int, int>> dirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int m = board.size(), n = board.back().size();

    std::queue<std::pair<int, int>> queue;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
          if (board[i][j] == 'O') {
            board[i][j] = '*';
            queue.emplace(i, j);
          }
        }
      }
    }

    while (!queue.empty()) {
      const auto [i, j] = queue.front();
      queue.pop();

      for (auto [di, dj] : dirs) {
        int r = i + di, c = j + dj;
        if (0 <= r && r < m && 0 <= c && c < n && board[r][c] == 'O') {
          board[r][c] = '*';
          queue.emplace(r, c);
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '*') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};

} // namespace bfs

namespace dfs {

// Time: O(NM)
// Space: O(1)
class Solution {
public:
  static void solve(std::vector<std::vector<char>> &board) {
    const int m = board.size(), n = board.back().size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
          dfs(i, j, board);
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '*') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }

private:
  static void dfs(int i, int j, std::vector<std::vector<char>> &board) {
    const int m = board.size(), n = board.back().size();
    if (i < 0 || i == m || j < 0 || j == n || board[i][j] != 'O') {
      return;
    }

    board[i][j] = '*';
    dfs(i + 1, j, board);
    dfs(i - 1, j, board);
    dfs(i, j + 1, board);
    dfs(i, j - 1, board);
  }
};

} // namespace dfs
