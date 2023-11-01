#pragma once

#include <algorithm>
#include <vector>

/*
  2154. Keep Multiplying Found Values by Two
  https://leetcode.com/problems/keep-multiplying-found-values-by-two/
  Difficulty: Easy
  Tags: Array, Hash Table, Sorting, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int findFinalValue(std::vector<int> nums, int original) {
    std::sort(nums.begin(), nums.end());
    for (auto a : nums) {
      if (a == original) {
        original <<= 1;
      }
    }
    return original;
  }
};
