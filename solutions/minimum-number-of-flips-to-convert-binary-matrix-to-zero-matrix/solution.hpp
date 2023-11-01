#pragma once

#include <algorithm>
#include <climits>
#include <vector>

/*
  1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
  https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
  Difficulty: Hard
  Tags: Array, Bit Manipulation, Breadth-First Search, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static int minFlips(std::vector<std::vector<int>> mat) {
    int min_flips = INT_MAX;
    dfs(0, 0, 0, &mat, &min_flips);
    return min_flips == INT_MAX ? -1 : min_flips;
  }

private:
  static void dfs(int i, int j, int flips, std::vector<std::vector<int>> *mat,
                  int *min_flips) {
    if (isZeroMatrix(*mat) && flips < *min_flips) {
      *min_flips = flips;
    }
    if (flips >= *min_flips) {
      return;
    }

    int m = mat->size(), n = mat->back().size();
    if (j == n) {
      if (++i == m) {
        return;
      }
      j = 0;
    }

    dfs(i, j + 1, flips, mat, min_flips);
    flipMatrix(i, j, *mat);
    dfs(i, j + 1, flips + 1, mat, min_flips);
    flipMatrix(i, j, *mat);
  }

  static bool isZeroMatrix(const std::vector<std::vector<int>> &mat) {
    for (size_t i = 0; i < mat.size(); ++i) {
      for (size_t j = 0; j < mat[i].size(); ++j) {
        if (mat[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  static void flipMatrix(int i, int j, std::vector<std::vector<int>> &mat) {
    static std::vector<std::pair<int, int>> dirs{
        {0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int m = mat.size(), n = mat.back().size();
    for (const auto &[di, dj] : dirs) {
      int x = i + di, y = j + dj;
      if (x >= 0 && y >= 0 && x < m && y < n) {
        mat[x][y] = 1 - mat[x][y];
      }
    }
  }
};
