#pragma once

#include <vector>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static std::vector<int> getRow(int rowIndex) {
    std::vector<int> triangle(rowIndex + 1, 1);
    for (int i = 1; i < rowIndex; ++i) {
      for (int j = 0; j < i; ++j) {
        triangle[i - j] += triangle[i - j - 1];
      }
    }
    return triangle;
  }
};
