#pragma once

#include <array>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static constexpr int kMaxValue = 100;

  static bool checkValid(const std::vector<std::vector<int>> &matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
      std::array<int, kMaxValue + 1> row{}, col{};
      for (size_t j = 0; j < matrix.size(); ++j) {
        if (row[matrix[i][j]]++ || col[matrix[j][i]]++) {
          return false;
        }
      }
    }
    return true;
  }
};
