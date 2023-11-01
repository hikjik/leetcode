#pragma once

#include <vector>

/*
  268. Missing Number
  https://leetcode.com/problems/missing-number/
  Difficulty: Easy
  Tags: Array, Hash Table, Math, Binary Search, Bit Manipulation, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int missingNumber(const std::vector<int> &nums) {
    int n = nums.size();
    return n * (n + 1) / 2 - std::accumulate(nums.begin(), nums.end(), 0);
  }
};
