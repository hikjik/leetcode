#pragma once

#include <algorithm>
#include <vector>

/*
  1572. Matrix Diagonal Sum
  https://leetcode.com/problems/matrix-diagonal-sum/
  Difficulty: Easy
  Tags: Array, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static int diagonalSum(const std::vector<std::vector<int>> &mat) {
    int n = mat.size(), m = mat.back().size();

    int sum = 0;
    for (int i = 0; i < std::min(n, m); ++i) {
      sum += mat[i][i];
      sum += i != m - i - 1 ? mat[i][m - i - 1] : 0;
    }
    return sum;
  }
};
