#pragma once

#include <ranges>
#include <vector>

// Time: O(NM)
// Space: O(1)

class Solution {
public:
  static void setZeroes(std::vector<std::vector<int>> &matrix) {
    const int m = matrix.size(), n = matrix.back().size();

    const bool unset_first_row = std::ranges::count(matrix[0], 0);

    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!matrix[i][j]) {
          matrix[i][0] = matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int j = n - 1; j >= 0; --j) {
        if (!matrix[i][0] || !matrix[0][j]) {
          matrix[i][j] = 0;
        }
      }
    }

    if (unset_first_row) {
      std::ranges::fill(matrix[0], 0);
    }
  }
};
