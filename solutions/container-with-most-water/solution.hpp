#pragma once

#include <algorithm>
#include <vector>

/*
  11. Container With Most Water
  https://leetcode.com/problems/container-with-most-water/
  Difficulty: Medium
  Tags: Array, Two Pointers, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int maxArea(const std::vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;
    while (left < right) {
      const auto area = std::min(height[left], height[right]) * (right - left);
      max_area = std::max(max_area, area);
      height[left] < height[right] ? left++ : right--;
    }
    return max_area;
  }
};
