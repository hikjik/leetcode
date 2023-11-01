#pragma once

#include <vector>

/*
  1037. Valid Boomerang
  https://leetcode.com/problems/valid-boomerang/
  Difficulty: Easy
  Tags: Array, Math, Geometry
  Time:
  Space:
*/

class Solution {
public:
  static bool isBoomerang(const std::vector<std::vector<int>> &points) {
    const auto x1 = points[0][0], y1 = points[0][1];
    const auto x2 = points[1][0], y2 = points[1][1];
    const auto x3 = points[2][0], y3 = points[2][1];
    return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) != 0;
  }
};
