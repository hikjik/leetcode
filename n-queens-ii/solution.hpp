#pragma once

#include <array>
#include <string>
#include <vector>

class Solution {
public:
  inline static const size_t MAX_BOARD_SIZE = 9;

  inline static std::array<bool, MAX_BOARD_SIZE> columns;
  inline static std::array<bool, MAX_BOARD_SIZE * 2 - 1> major_diag;
  inline static std::array<bool, MAX_BOARD_SIZE * 2 - 1> minor_diag;

  inline static size_t totalNQueens(size_t n) {
    size_t total = 0;
    totalNQueens(0, n, total);
    return total;
  }

  inline static void totalNQueens(size_t row, size_t n, size_t &total) {
    if (row == n) {
      total++;
      return;
    }

    for (size_t col = 0; col < n; ++col) {
      if (!columns[col] & !major_diag[row + col] &
          !minor_diag[row + n - col - 1]) {
        columns[col] = true;
        major_diag[row + col] = true;
        minor_diag[row + n - col - 1] = true;

        totalNQueens(row + 1, n, total);

        minor_diag[row + n - col - 1] = false;
        major_diag[row + col] = false;
        columns[col] = false;
      }
    }
  }
};
