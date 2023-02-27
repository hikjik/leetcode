#pragma once

#include <vector>

class Solution {
public:
  static std::vector<int> getRow(int row_index) {
    std::vector<int> triangle;
    for (int i = 0; i <= row_index; ++i) {
      std::vector<int> new_row(i + 1, 1);
      for (int j = 1; j < i; ++j) {
        new_row[j] = triangle[j - 1] + triangle[j];
      }
      triangle.swap(new_row);
    }
    return triangle;
  }
};
