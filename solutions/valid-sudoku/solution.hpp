#pragma once

#include <array>
#include <unordered_set>
#include <vector>

class Solution {
  static const size_t SUDOKU_SIZE = 9;
  static const char EMPTY = '.';

public:
  static bool isValidSudoku(const std::vector<std::vector<char>> &board) {
    std::array<std::unordered_set<int>, SUDOKU_SIZE> rows;
    std::array<std::unordered_set<int>, SUDOKU_SIZE> cols;
    std::array<std::unordered_set<int>, SUDOKU_SIZE> boxes;

    for (size_t i = 0; i < SUDOKU_SIZE; ++i) {
      for (size_t j = 0; j < SUDOKU_SIZE; ++j) {
        const auto c = board[i][j];
        if (c == EMPTY) {
          continue;
        }

        const size_t k = i / 3 * 3 + j / 3;

        if (rows[i].count(c) || cols[j].count(c) || boxes[k].count(c)) {
          return false;
        }

        rows[i].insert(c);
        cols[j].insert(c);
        boxes[k].insert(c);
      }
    }

    return true;
  }
};
