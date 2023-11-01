#pragma once

#include <algorithm>
#include <vector>

/*
  2848. Points That Intersect With Cars
  https://leetcode.com/problems/points-that-intersect-with-cars/
  Difficulty: Easy
  Tags: Hash Table, Math, Prefix Sum
  Time:
  Space:
*/

class Solution {
public:
  static int numberOfPoints(std::vector<std::vector<int>> nums) {
    std::sort(nums.begin(), nums.end());
    int count = 0, end = 0;
    for (const auto &pair : nums) {
      if (pair[1] > end) {
        count += pair[1] - std::max(pair[0] - 1, end);
        end = pair[1];
      }
    }
    return count;
  }
};
