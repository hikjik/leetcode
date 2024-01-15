#pragma once

#include <vector>

// Time: O(N^2M^2)
// Space: O(NM)

class Solution {
public:
  static std::vector<std::vector<int>>
  candyCrush(std::vector<std::vector<int>> board) {
    const int m = board.size(), n = board.back().size();
    for (bool crash = true; crash;) {
      crash = false;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          const auto candy = std::abs(board[i][j]);
          if (!candy) {
            continue;
          }
          if (i + 2 < m && std::abs(board[i + 1][j]) == candy &&
              std::abs(board[i + 2][j]) == candy) {
            board[i][j] = board[i + 1][j] = board[i + 2][j] = -candy;
            crash = true;
          }
          if (j + 2 < n && std::abs(board[i][j + 1]) == candy &&
              std::abs(board[i][j + 2]) == candy) {
            board[i][j] = board[i][j + 1] = board[i][j + 2] = -candy;
            crash = true;
          }
        }
      }

      if (crash) {
        for (int j = 0; j < n; ++j) {
          int l = m - 1;
          for (int r = m - 1; r >= 0; --r) {
            if (board[r][j] >= 0) {
              board[l--][j] = board[r][j];
            }
          }
          while (l >= 0) {
            board[l--][j] = 0;
          }
        }
      }
    }
    return board;
  }
};
