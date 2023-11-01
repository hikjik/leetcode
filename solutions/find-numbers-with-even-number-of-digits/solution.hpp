#pragma once

#include <algorithm>
#include <vector>

/*
  1295. Find Numbers with Even Number of Digits
  https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static int findNumbers(const std::vector<int> &nums) {
    return std::count_if(nums.begin(), nums.end(), [](int n) {
      return std::to_string(n).size() % 2 == 0;
    });
  }
};
