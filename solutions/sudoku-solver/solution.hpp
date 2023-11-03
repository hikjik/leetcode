#pragma once

#include <array>
#include <vector>

// Time: O(N^(N^2)), where N = 9
// Space: O(N^2)
// Notes: [Sudoku solving](https://w.wiki/3F$y)

class Solution {
public:
  static constexpr int kSize = 9;
  static constexpr char kEmpty = '.';

  std::array<std::array<bool, kSize>, kSize> row{}, col{}, box{};

  void solveSudoku(std::vector<std::vector<char>> &board) {
    initMasks(board);
    solveSudoku(0, 0, board);
  }

private:
  void initMasks(std::vector<std::vector<char>> &board) {
    for (int i = 0; i < kSize; ++i) {
      for (int j = 0; j < kSize; ++j) {
        if (board[i][j] != kEmpty) {
          const int c = board[i][j] - '1';
          const int k = i / 3 * 3 + j / 3;
          row[i][c] = col[j][c] = box[k][c] = true;
        }
      }
    }
  }

  bool solveSudoku(int i, int j, std::vector<std::vector<char>> &board) {
    if (j == kSize) {
      if (i == kSize - 1) {
        return true;
      }
      ++i, j = 0;
    }

    if (board[i][j] != kEmpty) {
      return solveSudoku(i, j + 1, board);
    }

    const auto k = i / 3 * 3 + j / 3;
    for (int c = 0; c < 9; ++c) {
      if (!row[i][c] && !col[j][c] && !box[k][c]) {
        row[i][c] = col[j][c] = box[k][c] = true;
        board[i][j] = '1' + c;
        if (solveSudoku(i, j + 1, board)) {
          return true;
        }
        board[i][j] = kEmpty;
        row[i][c] = col[j][c] = box[k][c] = false;
      }
    }
    return false;
  }
};
