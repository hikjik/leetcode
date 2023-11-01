#pragma once

#include <vector>

/*
  999. Available Captures for Rook
  https://leetcode.com/problems/available-captures-for-rook/
  Difficulty: Easy
  Tags: Array, Matrix, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int numRookCaptures(const std::vector<std::vector<char>> &board) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    const auto [i0, j0] = findRook(board);

    int ans = 0;
    for (const auto &[di, dj] : kDirs) {
      for (int i = i0 + di, j = j0 + dj; inBound(i, j); i += di, j += dj) {
        if (board[i][j] == 'p') {
          ++ans;
        }
        if (board[i][j] != '.') {
          break;
        }
      }
    }
    return ans;
  }

private:
  static bool inBound(int i, int j) {
    return 0 <= i && i < 8 && 0 <= j && j < 8;
  }

  static std::pair<int, int>
  findRook(const std::vector<std::vector<char>> &board) {
    for (int i = 0; i < std::ssize(board); ++i) {
      for (int j = 0; j < std::ssize(board.back()); ++j) {
        if (board[i][j] == 'R') {
          return {i, j};
        }
      }
    }
    throw;
  }
};
