#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static void solveSudoku(std::vector<std::vector<char>> &board) {
    solveSudoku(0, board);
  }

private:
  static bool solveSudoku(int step, std::vector<std::vector<char>> &board) {
    if (step == 81) {
      return true;
    }

    const auto i = step / 9, j = step % 9;
    if (board[i][j] != '.') {
      return solveSudoku(step + 1, board);
    }

    for (char c = '1'; c <= '9'; ++c) {
      if (isValid(i, j, c, board)) {
        board[i][j] = c;
        if (solveSudoku(step + 1, board)) {
          return true;
        }
        board[i][j] = '.';
      }
    }
    return false;
  }

  static bool isValid(int i, int j, char c,
                      const std::vector<std::vector<char>> &board) {
    for (int k = 0; k < 9; ++k) {
      if (board[i][k] == c || board[k][j] == c ||
          board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c) {
        return false;
      }
    }
    return true;
  }
};
