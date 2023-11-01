#pragma once

#include <vector>

/*
  1725. Number Of Rectangles That Can Form The Largest Square
  https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static int
  countGoodRectangles(const std::vector<std::vector<int>> &rectangles) {
    int max_length = 0, cnt = 0;
    for (const auto &rectangle : rectangles) {
      const auto length = std::min(rectangle[0], rectangle[1]);
      if (length > max_length) {
        max_length = length;
        cnt = 1;
      } else if (length == max_length) {
        ++cnt;
      }
    }
    return cnt;
  }
};
