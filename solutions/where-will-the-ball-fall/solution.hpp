#pragma once

#include <vector>

/*
  1706. Where Will the Ball Fall
  https://leetcode.com/problems/where-will-the-ball-fall/
  Difficulty: Medium
  Tags: Array, Dynamic Programming, Depth-First Search, Matrix, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> findBall(const std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid.back().size();

    std::vector<int> answer(n);
    for (int j = 0; j < n; ++j) {
      int col = j;
      for (int i = 0; i < m; ++i) {
        auto tmp = grid[i][col];
        col += grid[i][col];
        if (col < 0 || col > n - 1 || grid[i][col] != tmp) {
          col = -1;
          break;
        }
      }
      answer[j] = col;
    }
    return answer;
  }
};
