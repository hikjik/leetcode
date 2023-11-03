#pragma once

#include <array>
#include <string>
#include <vector>

// Time: O(N!)
// Space: O(N^2)

class Solution {
public:
  using ChessBoard = std::vector<std::string>;

  static constexpr size_t kSize = 9;

  std::array<bool, kSize> cols{};
  std::array<bool, kSize * 2 - 1> diag1{};
  std::array<bool, kSize * 2 - 1> diag2{};

  std::vector<ChessBoard> solveNQueens(size_t n) {
    std::vector<ChessBoard> boards;
    ChessBoard board(n, std::string(n, '.'));
    solveNQueens(0, board, boards);
    return boards;
  }

  void solveNQueens(int r, ChessBoard &board, std::vector<ChessBoard> &boards) {
    const int n = board.size();
    if (r == n) {
      boards.push_back(board);
      return;
    }

    for (int c = 0; c < n; ++c) {
      if (!cols[c] && !diag1[r + c] && !diag2[r + n - c - 1]) {
        board[r][c] = 'Q';
        cols[c] = diag1[r + c] = diag2[r + n - c - 1] = true;
        solveNQueens(r + 1, board, boards);
        cols[c] = diag1[r + c] = diag2[r + n - c - 1] = false;
        board[r][c] = '.';
      }
    }
  }
};
