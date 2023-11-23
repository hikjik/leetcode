#pragma once

#include <vector>

// Time: O(N^2)
// Space: O(1)

class Solution {
public:
  static std::vector<std::vector<int>> generateMatrix(int n) {
    static const std::vector<int> kDirs{0, 1, 0, -1, 0};

    std::vector ans(n, std::vector<int>(n, -1));
    int i = 0, j = 0;
    int d = 0;
    for (int value = 1; value <= n * n; ++value) {
      ans[i][j] = value;
      const auto r = i + kDirs[d], c = j + kDirs[d + 1];
      if (r < 0 || r >= n || c < 0 || c >= n || ans[r][c] != -1) {
        d = (d + 1) % 4;
      }
      i += kDirs[d], j += kDirs[d + 1];
    }
    return ans;
  }
};
