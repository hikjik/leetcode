#pragma once

#include <vector>

class Solution {
public:
  static std::vector<int>
  spiralOrder(const std::vector<std::vector<int>> &matrix) {
    int n = matrix.size(), m = matrix.back().size();

    std::vector<int> nums;
    nums.reserve(n * m);

    int r1 = 0, r2 = n;
    int c1 = 0, c2 = m;
    while (nums.size() < matrix.size() * matrix.back().size()) {
      for (int j = c1; j < c2 && r1 != r2; ++j) {
        nums.push_back(matrix[r1][j]);
      }
      r1++;
      for (int i = r1; i < r2 && c1 != c2; ++i) {
        nums.push_back(matrix[i][c2 - 1]);
      }
      c2--;
      for (int j = c2 - 1; j >= c1 && r1 != r2; --j) {
        nums.push_back(matrix[r2 - 1][j]);
      }
      r2--;
      for (int i = r2 - 1; i >= r1 && c1 != c2; --i) {
        nums.push_back(matrix[i][c1]);
      }
      c1++;
    }
    return nums;
  }
};
