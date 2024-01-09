#pragma once

#include <vector>

// Time: O(N+M)
// Space: O(1)

class BinaryMatrix {
public:
  explicit BinaryMatrix(std::vector<std::vector<int>> mat)
      : mat(std::move(mat)) {}

  int get(int row, int col) const {
    ++calls;
    return mat[row][col];
  }

  std::vector<int> dimensions() const {
    const int m = mat.size(), n = mat.back().size();
    return {m, n};
  }

  int getNumberOfCalls() const { return calls; }

private:
  std::vector<std::vector<int>> mat;
  mutable int calls = 0;
};

class Solution {
public:
  static int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    const auto dims = binaryMatrix.dimensions();
    const auto m = dims[0], n = dims[1];

    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
      if (binaryMatrix.get(i, j)) {
        --j;
      } else {
        ++i;
      }
    }
    return j == n - 1 ? -1 : j + 1;
  }
};
