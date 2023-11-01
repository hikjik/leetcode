#pragma once

#include <vector>

/*
  2078. Two Furthest Houses With Different Colors
  https://leetcode.com/problems/two-furthest-houses-with-different-colors/
  Difficulty: Easy
  Tags: Array, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int maxDistance(const std::vector<int> &colors) {
    size_t left = 0, right = colors.size() - 1;
    while (colors[left] == colors.back()) {
      ++left;
    }
    while (colors.front() == colors[right]) {
      --right;
    }
    return std::max(right, colors.size() - left - 1);
  }
};
