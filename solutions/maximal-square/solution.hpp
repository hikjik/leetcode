#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int maximalSquare(const std::vector<std::vector<char>> &matrix) {
    size_t m = matrix.size(), n = matrix.back().size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    int max_length = 0;
    for (size_t i = 1; i < m + 1; ++i) {
      for (size_t j = 1; j < n + 1; ++j) {
        if (matrix[i - 1][j - 1] == '1') {
          dp[i][j] =
              std::min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
        }
        max_length = std::max(max_length, dp[i][j]);
      }
    }
    return max_length * max_length;
  }
};
