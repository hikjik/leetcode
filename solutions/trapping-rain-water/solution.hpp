#pragma once

#include <vector>

/*
  42. Trapping Rain Water
  https://leetcode.com/problems/trapping-rain-water/
  Difficulty: Hard
  Tags: Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
  Time:
  Space:
*/

class Solution {
public:
  static int trap(const std::vector<int> &heights) {
    if (heights.empty()) {
      return 0;
    }

    size_t left = 0, right = heights.size() - 1;
    int max_left = heights[left], max_right = heights[right];

    int water_count = 0;
    while (left < right) {
      if (max_left <= max_right) {
        left++;
        max_left = std::max(max_left, heights[left]);
        water_count += max_left - heights[left];
      } else {
        right--;
        max_right = std::max(max_right, heights[right]);
        water_count += max_right - heights[right];
      }
    }
    return water_count;
  }
};