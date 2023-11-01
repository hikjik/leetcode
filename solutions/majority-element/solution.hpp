#pragma once

#include <vector>

/*
  169. Majority Element
  https://leetcode.com/problems/majority-element/
  Difficulty: Easy
  Tags: Array, Hash Table, Divide and Conquer, Sorting, Counting
  Time:
  Space:
*/

class Solution {
public:
  static int majorityElement(const std::vector<int> &nums) {
    int cnt = 0, majority = 0;
    for (auto num : nums) {
      if (!cnt) {
        majority = num;
      }
      cnt += majority == num ? 1 : -1;
    }
    return majority;
  }
};
