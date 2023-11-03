#pragma once

#include <array>
#include <vector>

// Time: O(1)
// Space: O(1)

class Solution {
  static constexpr int kSize = 9;
  static constexpr char kEmpty = '.';

public:
  static bool isValidSudoku(const std::vector<std::vector<char>> &board) {
    std::array<std::array<bool, kSize>, kSize> row{}, col{}, box{};
    for (int i = 0; i < kSize; ++i) {
      for (int j = 0; j < kSize; ++j) {
        if (board[i][j] == kEmpty) {
          continue;
        }
        const auto c = board[i][j] - '1';
        const auto k = i / 3 * 3 + j / 3;
        if (row[i][c] || col[j][c] || box[k][c]) {
          return false;
        }
        row[i][c] = col[j][c] = box[k][c] = true;
      }
    }
    return true;
  }
};
