#pragma once

#include <quad_node.h>

#include <vector>

/*
  427. Construct Quad Tree
  https://leetcode.com/problems/construct-quad-tree/
  Difficulty: Medium
  Tags: Array, Divide and Conquer, Tree, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static Node *construct(const std::vector<std::vector<int>> &grid) {
    return construct(0, 0, grid.size(), grid);
  }

private:
  static Node *construct(size_t i, size_t j, size_t n,
                         const std::vector<std::vector<int>> &grid) {
    if (isSame(i, j, n, grid)) {
      return new Node(grid[i][j], true);
    }

    return new Node(false, false, construct(i, j, n / 2, grid),
                    construct(i, j + n / 2, n / 2, grid),
                    construct(i + n / 2, j, n / 2, grid),
                    construct(i + n / 2, j + n / 2, n / 2, grid));
  }

  static bool isSame(size_t i, size_t j, size_t n,
                     const std::vector<std::vector<int>> &grid) {
    for (size_t r = i; r < i + n; ++r) {
      for (size_t c = j; c < j + n; ++c) {
        if (grid[r][c] != grid[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
};
