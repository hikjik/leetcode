#pragma once

#include <vector>

// Time: O(NMlogNM)
// Space: O(1)

class Solution {
public:
  static bool searchMatrix(const std::vector<std::vector<int>> &matrix,
                           int target) {
    const int rows = matrix.size(), cols = matrix.back().size();
    auto left = 0, right = rows * cols;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      const auto element = matrix[middle / cols][middle % cols];
      if (element == target) {
        return true;
      }
      element < target ? left = middle + 1 : right = middle;
    }
    return false;
  }
};
