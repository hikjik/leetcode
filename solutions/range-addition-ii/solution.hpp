#pragma once

#include <vector>

/*
  598. Range Addition II
  https://leetcode.com/problems/range-addition-ii/
  Difficulty: Easy
  Tags: Array, Math
  Time:
  Space:
*/

class Solution {
public:
  static int maxCount(int m, int n, const std::vector<std::vector<int>> &ops) {
    std::vector<int> min{m, n};
    for (const auto &op : ops) {
      for (int i = 0; i < 2; ++i) {
        min[i] = std::min(min[i], op[i]);
      }
    }
    return min[0] * min[1];
  }
};
