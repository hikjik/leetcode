#pragma once

#include <vector>

/*
  986. Interval List Intersections
  https://leetcode.com/problems/interval-list-intersections/
  Difficulty: Medium
  Tags: Array, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<int>>
  intervalIntersection(const std::vector<std::vector<int>> &first_list,
                       const std::vector<std::vector<int>> &second_list) {
    std::vector<std::vector<int>> intersections;
    size_t i = 0, j = 0;
    while (i < first_list.size() && j < second_list.size()) {
      const auto left = std::max(first_list[i][0], second_list[j][0]);
      const auto right = std::min(first_list[i][1], second_list[j][1]);
      if (left <= right) {
        intersections.push_back({left, right});
      }
      first_list[i][1] <= second_list[j][1] ? i++ : j++;
    }
    return intersections;
  }
};
