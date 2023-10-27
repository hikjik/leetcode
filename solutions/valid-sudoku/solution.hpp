#pragma once

#include <array>
#include <unordered_set>
#include <vector>

class Solution {
  static const size_t kSize = 9;
  static const char kEmpty = '.';

public:
  static bool isValidSudoku(const std::vector<std::vector<char>> &board) {
    std::array<std::unordered_set<int>, kSize> rows;
    std::array<std::unordered_set<int>, kSize> cols;
    std::array<std::unordered_set<int>, kSize> boxes;

    for (size_t i = 0; i < kSize; ++i) {
      for (size_t j = 0; j < kSize; ++j) {
        const auto c = board[i][j];
        if (c == kEmpty) {
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
