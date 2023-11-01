#pragma once

#include <vector>

/*
  2319. Check if Matrix Is X-Matrix
  https://leetcode.com/problems/check-if-matrix-is-x-matrix/
  Difficulty: Easy
  Tags: Array, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static bool checkXMatrix(const std::vector<std::vector<int>> &grid) {
    const int n = grid.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j || i == n - j - 1) {
          if (!grid[i][j]) {
            return false;
          }
        } else {
          if (grid[i][j]) {
            return false;
          }
        }
      }
    }
    return true;
  }
};
