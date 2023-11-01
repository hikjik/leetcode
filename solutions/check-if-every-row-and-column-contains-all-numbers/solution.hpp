#pragma once

#include <array>
#include <vector>

/*
  2133. Check if Every Row and Column Contains All Numbers
  https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
  Difficulty: Easy
  Tags: Array, Hash Table, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static constexpr int kMaxValue = 100;

  static bool checkValid(const std::vector<std::vector<int>> &matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
      std::array<int, kMaxValue + 1> row{}, col{};
      for (size_t j = 0; j < matrix.size(); ++j) {
        if (row[matrix[i][j]]++ || col[matrix[j][i]]++) {
          return false;
        }
      }
    }
    return true;
  }
};
