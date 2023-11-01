#pragma once

#include <vector>

/*
  867. Transpose Matrix
  https://leetcode.com/problems/transpose-matrix/
  Difficulty: Easy
  Tags: Array, Matrix, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<int>>
  transpose(const std::vector<std::vector<int>> &matrix) {
    const int n = matrix.size(), m = matrix.back().size();

    std::vector transposed(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        transposed[i][j] = matrix[j][i];
      }
    }
    return transposed;
  }
};
