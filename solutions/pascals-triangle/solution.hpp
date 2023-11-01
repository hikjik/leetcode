#pragma once

#include <vector>

/*
  118. Pascal's Triangle
  https://leetcode.com/problems/pascals-triangle/
  Difficulty: Easy
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<int>> generate(size_t numRows) {
    std::vector<std::vector<int>> triangle(numRows);
    for (size_t i = 0; i < numRows; ++i) {
      triangle[i].resize(i + 1, 1);
      for (size_t j = 1; j < i; ++j) {
        triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }
    }
    return triangle;
  }
};
