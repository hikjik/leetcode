#pragma once

#include <vector>

// Time: O(N^2)
// Space: O(N^2)

class Solution {
public:
  static std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> triangle(numRows);
    for (int i = 0; i < numRows; ++i) {
      triangle[i].resize(i + 1, 1);
      for (int j = 1; j < i; ++j) {
        triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }
    }
    return triangle;
  }
};
