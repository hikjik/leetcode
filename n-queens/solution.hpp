#pragma once

#include <array>
#include <string>
#include <vector>

using ChessBoard = std::vector<std::string>;

class Solution {
public:
  inline static const size_t MAX_BOARD_SIZE = 9;

  inline static std::array<bool, MAX_BOARD_SIZE> columns;
  inline static std::array<bool, MAX_BOARD_SIZE * 2 - 1> major_diag;
  inline static std::array<bool, MAX_BOARD_SIZE * 2 - 1> minor_diag;

  inline static std::vector<ChessBoard> solveNQueens(size_t n) {
    std::vector<ChessBoard> boards;
    ChessBoard board(n, std::string(n, '.'));

    solveNQueens(0, board, boards);
    return boards;
  }

  inline static void solveNQueens(size_t row, ChessBoard &board,
                                  std::vector<ChessBoard> &boards) {
    size_t n = board.size();

    if (row == n) {
      boards.push_back(board);
      return;
    }

    for (size_t col = 0; col < n; ++col) {
      if (!columns[col] & !major_diag[row + col] &
          !minor_diag[row + n - col - 1]) {
        board[row][col] = 'Q';
        columns[col] = true;
        major_diag[row + col] = true;
        minor_diag[row + n - col - 1] = true;

        solveNQueens(row + 1, board, boards);

        minor_diag[row + n - col - 1] = false;
        major_diag[row + col] = false;
        columns[col] = false;
        board[row][col] = '.';
      }
    }
  }
};
