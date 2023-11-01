#pragma once

#include <algorithm>
#include <vector>

/*
  289. Game of Life
  https://leetcode.com/problems/game-of-life/
  Difficulty: Medium
  Tags: Array, Matrix, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static void gameOfLife(std::vector<std::vector<int>> &board) {
    const int m = board.size(), n = board.back().size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int ones = 0;
        for (int x = std::max(0, i - 1); x <= std::min(m - 1, i + 1); ++x) {
          for (int y = std::max(0, j - 1); y <= std::min(n - 1, j + 1); ++y) {
            if (x != i || y != j) {
              ones += board[x][y] & 1;
            }
          }
        }

        if (board[i][j] && (ones == 2 || ones == 3)) {
          board[i][j] |= 0b10;
        }

        if (!board[i][j] && ones == 3) {
          board[i][j] |= 0b10;
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        board[i][j] >>= 1;
      }
    }
  }
};