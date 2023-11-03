#pragma once

#include <vector>

// Time: O(N^2)
// Space: O(1)

class Solution {
public:
  static std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector matrix(n, std::vector<int>(n));
    int r1 = 0, r2 = n, c1 = 0, c2 = n;
    for (int value = 0; value < n * n;) {
      for (int j = c1; j < c2 && r1 != r2; ++j) {
        matrix[r1][j] = ++value;
      }
      ++r1;
      for (int i = r1; i < r2 && c1 != c2; ++i) {
        matrix[i][c2 - 1] = ++value;
      }
      --c2;
      for (int j = c2 - 1; j >= c1 && r1 != r2; --j) {
        matrix[r2 - 1][j] = ++value;
      }
      --r2;
      for (int i = r2 - 1; i >= r1 && c1 != c2; --i) {
        matrix[i][c1] = ++value;
      }
      ++c1;
    }
    return matrix;
  }
};
