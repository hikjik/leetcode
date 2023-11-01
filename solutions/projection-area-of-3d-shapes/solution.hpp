#pragma once

#include <vector>

/*
  883. Projection Area of 3D Shapes
  https://leetcode.com/problems/projection-area-of-3d-shapes/
  Difficulty: Easy
  Tags: Array, Math, Geometry, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static int projectionArea(const std::vector<std::vector<int>> &grid) {
    int area = 0;
    for (int i = 0; i < std::ssize(grid); ++i) {
      int row = 0, col = 0;
      for (int j = 0; j < std::ssize(grid); ++j) {
        row = std::max(row, grid[i][j]);
        col = std::max(col, grid[j][i]);
        area += grid[i][j] > 0;
      }
      area += row + col;
    }
    return area;
  }
};
