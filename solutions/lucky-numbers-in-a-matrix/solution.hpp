#pragma once

#include <ranges>
#include <vector>

/*
  1380. Lucky Numbers in a Matrix
  https://leetcode.com/problems/lucky-numbers-in-a-matrix/
  Difficulty: Easy
  Tags: Array, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int>
  luckyNumbers(const std::vector<std::vector<int>> &matrix) {
    std::vector<int> ans;
    for (const auto &row : matrix) {
      const auto j = std::distance(row.begin(), std::ranges::min_element(row));
      if (std::ranges::all_of(
              matrix, [&](const auto &other) { return row[j] >= other[j]; })) {
        ans.push_back(row[j]);
      }
    }
    return ans;
  }
};
