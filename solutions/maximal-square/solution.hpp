#pragma once

#include <algorithm>
#include <vector>

// Time: O(NM)
// Space: O(NM)

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int maximalSquare(const std::vector<std::vector<char>> &matrix) {
    const int m = matrix.size(), n = matrix.back().size();
    std::vector dp(m + 1, std::vector<int>(n + 1));
    int len = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '0') {
          continue;
        }
        dp[i + 1][j + 1] = 1 + std::min({dp[i][j], dp[i + 1][j], dp[i][j + 1]});
        len = std::max(len, dp[i + 1][j + 1]);
      }
    }
    return len * len;
  }
};

} // namespace dp

namespace optimized {

// Time: O(NM)
// Space: O(N)
class Solution {
public:
  static int maximalSquare(const std::vector<std::vector<char>> &matrix) {
    const int m = matrix.size(), n = matrix.back().size();
    std::vector<int> dp(n + 1);
    int len = 0;
    for (int i = 0; i < m; ++i) {
      int prev = 0;
      for (int j = 0; j < n; ++j) {
        std::swap(prev, dp[j + 1]);
        if (matrix[i][j] == '0') {
          dp[j + 1] = 0;
        } else {
          dp[j + 1] = 1 + std::min({prev, dp[j + 1], dp[j]});
          len = std::max(len, dp[j + 1]);
        }
      }
    }
    return len * len;
  }
};

} // namespace optimized
