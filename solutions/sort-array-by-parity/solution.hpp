#pragma once

#include <algorithm>
#include <vector>

/*
  905. Sort Array By Parity
  https://leetcode.com/problems/sort-array-by-parity/
  Difficulty: Easy
  Tags: Array, Two Pointers, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> sortArrayByParity(std::vector<int> nums) {
    std::partition(nums.begin(), nums.end(), [](int a) { return a % 2 == 0; });
    return nums;
  }
};
