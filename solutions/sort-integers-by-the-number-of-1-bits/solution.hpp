#pragma once

#include <algorithm>
#include <vector>

/*
  1356. Sort Integers by The Number of 1 Bits
  https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
  Difficulty: Easy
  Tags: Array, Bit Manipulation, Sorting, Counting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> sortByBits(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
      return std::forward_as_tuple(__builtin_popcount(a), a) <
             std::forward_as_tuple(__builtin_popcount(b), b);
    });
    return arr;
  }
};
