#pragma once

#include <vector>

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
