#pragma once

#include <vector>

// Time: O(Q^2)
// Space: O(NM + Q)

namespace brute_force {

// Q is the number of operations
// N x M is the shape of the rectangle
// Time: O(QNM)
// Space: O(NM)

class SubrectangleQueries {
public:
  // O(NM)
  SubrectangleQueries(const std::vector<std::vector<int>> &rectangle)
      : rectangle(rectangle) {}

  // O(NM)
  void updateSubrectangle(int row1, int col1, int row2, int col2,
                          int newValue) {
    for (int i = row1; i <= row2; ++i) {
      for (int j = col1; j <= col2; ++j) {
        rectangle[i][j] = newValue;
      }
    }
  }

  // O(1)
  int getValue(int row, int col) const { return rectangle[row][col]; }

private:
  std::vector<std::vector<int>> rectangle;
};

} // namespace brute_force

namespace optimized {

// Q is the number of operations
// N x M is the shape of the rectangle
// Time: O(Q^2)
// Space: O(NM + Q)

class SubrectangleQueries {
  struct Op {
    int row1, col1;
    int row2, col2;
    int value;

    bool contains(int row, int col) const {
      return row1 <= row && row <= row2 && col1 <= col && col <= col2;
    }
  };

public:
  // O(NM)
  SubrectangleQueries(const std::vector<std::vector<int>> &rectangle)
      : rectangle(rectangle) {}

  // O(1)
  void updateSubrectangle(int row1, int col1, int row2, int col2,
                          int newValue) {
    ops.push_back({row1, col1, row2, col2, newValue});
  }

  // O(|ops|)
  int getValue(int row, int col) const {
    for (int i = ops.size() - 1; i >= 0; --i) {
      if (ops[i].contains(row, col)) {
        return ops[i].value;
      }
    }
    return rectangle[row][col];
  }

private:
  std::vector<std::vector<int>> rectangle;
  std::vector<Op> ops;
};

} // namespace optimized
