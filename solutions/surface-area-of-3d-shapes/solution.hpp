#pragma once

#include <vector>

/*
  892. Surface Area of 3D Shapes
  https://leetcode.com/problems/surface-area-of-3d-shapes/
  Difficulty: Easy
  Tags: Array, Math, Geometry, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static int surfaceArea(const std::vector<std::vector<int>> &grid) {
    int area = 0;
    for (int i = 0; i < std::ssize(grid); ++i) {
      for (int j = 0; j < std::ssize(grid); ++j) {
        if (grid[i][j]) {
          area += 4 * grid[i][j] + 2;
          if (i) {
            area -= 2 * std::min(grid[i][j], grid[i - 1][j]);
          }
          if (j) {
            area -= 2 * std::min(grid[i][j], grid[i][j - 1]);
          }
        }
      }
    }
    return area;
  }
};
