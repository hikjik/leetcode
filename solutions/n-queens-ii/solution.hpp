#pragma once

#include <array>
#include <string>
#include <vector>

/*
  52. N-Queens II
  https://leetcode.com/problems/n-queens-ii/
  Difficulty: Hard
  Tags: Backtracking
  Time:
  Space:
*/

class Solution {
public:
  static constexpr size_t kSize = 9;

  inline static std::array<bool, kSize> columns;
  inline static std::array<bool, kSize * 2 - 1> major_diag;
  inline static std::array<bool, kSize * 2 - 1> minor_diag;

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
