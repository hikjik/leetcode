#pragma once

#include <algorithm>
#include <cmath>
#include <vector>

/*
  2239. Find Closest Number to Zero
  https://leetcode.com/problems/find-closest-number-to-zero/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static int findClosestNumber(const std::vector<int> &nums) {
    return *std::min_element(nums.begin(), nums.end(), [](int a, int b) {
      return std::make_tuple(std::abs(a), b) < std::make_tuple(std::abs(b), a);
    });
  }
};
