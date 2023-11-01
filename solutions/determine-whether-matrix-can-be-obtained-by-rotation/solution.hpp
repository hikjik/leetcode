#pragma once

#include <algorithm>
#include <vector>

template <typename T> using Matrix = std::vector<std::vector<int>>;

/*
  1886. Determine Whether Matrix Can Be Obtained By Rotation
  https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
  Difficulty: Easy
  Tags: Array, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static bool findRotation(const Matrix<int> &mat, const Matrix<int> &target) {
    int n = mat.size();
    std::vector<bool> check(4, true);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        check[0] = check[0] & mat[i][j] == target[i][j];
        check[1] = check[1] & mat[i][j] == target[j][n - i - 1];
        check[2] = check[2] & mat[i][j] == target[n - i - 1][n - j - 1];
        check[3] = check[3] & mat[i][j] == target[n - j - 1][i];
      }
    }
    return check[0] || check[1] || check[2] || check[3];
  }
};
