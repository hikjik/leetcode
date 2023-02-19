#pragma once

#include <vector>

template <typename T> using Matrix = std::vector<std::vector<T>>;

class Solution {
public:
  static Matrix<int> matrixReshape(const Matrix<int> &mat, size_t rows,
                                   size_t cols) {
    if (rows * cols != mat.size() * mat.back().size()) {
      return mat;
    }

    Matrix<int> reshaped(rows, std::vector<int>(cols));
    size_t r = 0, c = 0;
    for (size_t i = 0; i < reshaped.size(); ++i) {
      for (size_t j = 0; j < reshaped.back().size(); ++j) {
        reshaped[i][j] = mat[r][c++];
        if (c == mat.back().size()) {
          c = 0, r++;
        }
      }
    }
    return reshaped;
  }
};
